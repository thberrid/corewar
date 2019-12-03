#!/bin/bash

TESTER='./tester'
YOUR_VM='./corewar'
ZAZ_VM='./documents/vm_champs/corewar'

# Option to be passed to both vms
VM_OPT='-a -v 31'

# The option to make your vm dump the memory as zaz's one do it (same format).
DUMP_OPT='-d'

# Files used to compare the output results.
YOUR_OUT_FILE='yout.dump'
ZAZ_OUT_FILE='zout.dump'

# path (and eventually arguments) to a valid OSX container to be used
#	when not on a real OSX system.
OSX_CONTAINER='darling shell'

# path to op.h file (to gather the opcode list)
op_h_file='./includes/op.h'

# Check for dependencies and make them if possible
init_tests()
{
	loop=1
	TOTAL_OP=0
	PASSED_OP=0
	TOTAL_RUN=0
	PASSED_RUN=0

	if [ -t 1 ]; then
		COL_NRM='\e[0m'
		COL_RED='\e[31m'
		COL_GRN='\e[32m'
		COL_CYA='\e[36m'
		COL_MAG='\e[35m'
	else
		COL_NRM=''
		COL_RED=''
		COL_GRN=''
		COL_MAG=''
		COL_CYA=''
	fi

	if [[ ! -n $1 ]]; then
		print_usage
		exit
	fi
	can_run=true
	if [[ `uname` == "Darwin" ]]; then
		unset OSX_CONTAINER
	else if [[ `uname` != "Linux" ]]; then
			echo "This script works only on OSX or Linux" >2
			exit
		fi
		command -v $OSX_CONTAINER > /dev/null
		if [[ $? -ne 0 ]]; then
			can_run=false
			printf "\e[31merror:\e[0m command '`echo $OSX_CONTAINER | cut -d' ' -f1`' does not exist.\n" >&2
		fi
	fi

	if [[ ! -f $TESTER ]]; then
		echo "Compiling $TESTER..."
		make -s $TESTER
		if [[ $? -ne 0 ]]; then
			can_run=false
		fi
	else
		make -s $TESTER
	fi

	if [[ ! -f `echo $YOUR_VM | cut -d' ' -f1` ]]; then
		echo "Compiling $YOUR_VM..."
		make -s $YOUR_VM ZAZ=TRUE
		if [[ $? -ne 0 ]]; then
			can_run=false
		fi
	else
		make -s $YOUR_VM
	fi

	if [[ ! -f `echo $ZAZ_VM | cut -d' ' -f1` ]]; then
		printf "\e[31merror:\e[0m $ZAZ_VM does not exist.\n" >&2
		can_run=false
	fi

	if [[ $can_run = false ]]; then
		exit
	fi
	unset can_run
}

# Print the help
print_usage()
{
	coma=''
	# Usage: ./run.sh [[num] opcode1|all|clear] ...
	printf "Usage:\n  $COL_GRN$0$COL_NRM [[""$COL_CYA""num$COL_NRM] ""$COL_CYA""opcode$COL_NRM|$COL_CYA""all$COL_NRM|$COL_CYA""clear$COL_NRM] ...\n"
	printf "      ""$COL_CYA""num$COL_NRM: repeat the next test multiple times\n"
	printf "      ""$COL_CYA""all$COL_NRM: test all opcodes\n"
	printf "      ""$COL_CYA""clear$COL_NRM: clears the test directory\n"
	printf "      ""$COL_CYA""opcode$COL_NRM: the opcode to be tested\n"
	printf "valid opcodes are ("
	for code in `op_list`; do
		printf "$coma$COL_MAG%s$COL_NRM" $code
		coma=','
	done
	printf ")\n"
	unset coma
}

# Run a comparaison.
#	First argument is the number of cycles before dump.
#	Second is the champion file used to test
compare_corewar()
{
	#$YOUR_VM $VM_OPT $DUMP_OPT $1 $2 > $YOUR_OUT_FILE && $OSX_CONTAINER $ZAZ_VM $VM_OPT -d $1 $2 > $ZAZ_OUT_FILE
	$YOUR_VM $VM_OPT $@ > $YOUR_OUT_FILE && $OSX_CONTAINER $ZAZ_VM $@ > $ZAZ_OUT_FILE
	if [[ $? -ne 0 ]]; then
		exit
	fi
	diff --suppress-common-lines -y $YOUR_OUT_FILE $ZAZ_OUT_FILE >/dev/null 2>/dev/null
	if [[ $? -ne 0 ]]; then
		if [[ $total -eq 0 ]]; then
			echo
		fi
		printf "$COL_MAG$1$COL_NRM:\n"
		diff --suppress-common-lines -y $YOUR_OUT_FILE $ZAZ_OUT_FILE
		mv $1 `echo $1 | sed 's:.cor:.fail.cor:g'`
		return 1
	else
		if [[ $VERBOSITY = true ]]; then
			printf "$COL_MAG$1$COL_NRM: $COL_GRN""OK$COL_NRM\n"
		fi
		return 0
	fi
}

# prints the number of cycles consumed by the opcode given as parameter
get_op_cost()
{
	cat $op_h_file|grep "{\"$1\", "|tr -d ' \t'|sed -E 's:\{(((T_IND|T_DIR|T_REG|0)\|?)+,?){1,3}\},::g'|cut -d',' -f4
}

# prints the available opcodes
op_list()
{
	cat $op_h_file|grep -Eo '\{\"[a-z]+\"'|grep -Eo "[a-z]+"|tr '\n' ' '|sed 's:nop ::g'
}

# Generate test files and test the vm with them
test_opcode()
{
	clear_tests $1
	./tester $1 > /dev/null
	if [[ $? -ne 0 ]]; then
		printf "\e[31merror:\e[0m '$1': invalid instruction\n" >&2
		print_usage
		exit
	else
		printf "$COL_CYA Testing '$COL_MAG$1$COL_CYA' %$((5-${#1}))s:$COL_NRM "
	fi
	total=0
	passed=0
	for file in `find tests/$1 -type f -name "*.cor"|sort -n -t'/' -k3`
	do
		#get_op_cost $1
		compare_corewar $file $VM_OPT $DUMP_OPT `get_op_cost $1`
		if [[ $? -eq 0 ]]; then
			passed=$((passed+1))
		fi
		total=$((total+1))
	done
	rm -f $ZAZ_OUT_FILE
	rm -f $YOUR_OUT_FILE
	if [[ $passed -eq $total ]]; then
		printf "$COL_GRN"
	else
		printf "$COL_RED"
	fi
	TOTAL_RUN=$((TOTAL_RUN+$total))
	PASSED_RUN=$((PASSED_RUN+$passed))
	printf "%d/%d$COL_NRM" $passed $total
	if [[ $passed -eq $total ]]; then
		printf " Well done !"
	fi
	printf "\n"
}

#test_file()
#{
#
#}

clear_tests()
{
	if [[ -n $1 ]]; then
		for f in "$@"; do
			rm -rf "./tests/$f/"
		done
	else
		rm -rf "./tests/"
	fi
}

# Startpoint

#if [[ $1 == "clear" ]]; then
#	clear_tests
#fi

#op_list
#exit
init_tests $1

for op in "$@"; do
	if [[ $op == "clear" ]]; then
		clear_tests
	elif [[ $op =~ ^[0-9]+$ ]] ; then
		loop=$op
	else
		if [[ $op == "all" ]]; then
			for cop in `op_list`; do
				test_opcode $cop
				if [[ $TOTAL_RUN -eq $PASSED_RUN ]]; then
					PASSED_OP=$((PASSED_OP+1))
				fi
				TOTAL_OP=$((TOTAL_OP+1))
			done
		else
			while [[ $loop -gt 0 ]]; do
				test_opcode $op
				loop=$((loop-1))
			done
			if [[ $TOTAL_RUN -eq $PASSED_RUN ]]; then
				PASSED_OP=$((PASSED_OP+1))
			fi
			TOTAL_OP=$((TOTAL_OP+1))
		fi
		loop=1
	fi
done

if [[ $TOTAL_RUN -ne 0 ]]; then
	if [[ $TOTAL_OP -eq $PASSED_OP ]]; then
		printf "$COL_GRN"
	else
		printf "$COL_RED"
	fi

	printf "%d/%d$COL_NRM(" $PASSED_OP $TOTAL_OP

	if [[ $TOTAL_RUN -eq $PASSED_RUN ]]; then
		printf "$COL_CYA"
	else
		printf "$COL_RED"
	fi

	printf "%d/%d$COL_NRM)\n" $PASSED_RUN $TOTAL_RUN
fi
