#!/bin/bash

TESTER='./tester'
YOUR_VM='./corewar'
ZAZ_VM='./documents/vm_champs/corewar'

# The option to make your vm dump the memory as zaz's one do it (same format).
DUMP_OPT='-zdump'

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

	if [[ ! -n $1 ]]; then
		print_usage
		exit
	fi
	can_run=true
	if [[ `uname` == "Darwin" ]]; then
		unset OSX_CONTAINER
	else if [[ `uname` != "Linux" ]]; then
			echo "This script works only on OSX or Linux"
			exit
		fi
		command -v $OSX_CONTAINER > /dev/null
		if [[ $? -ne 0 ]]; then
			can_run=false
			printf "\e[31merror:\e[0m command '`echo $OSX_CONTAINER | cut -d' ' -f1`' does not exist.\n"
		fi
	fi

	if [[ ! -f $TESTER ]]; then
		echo "Compiling $TESTER..."
		make -s $TESTER
		if [[ $? -ne 0 ]]; then
			can_run=false
		fi
	fi

	if [[ ! -f $YOUR_VM ]]; then
		echo "Compiling $YOUR_VM..."
		make -s $YOUR_VM
		if [[ $? -ne 0 ]]; then
			can_run=false
		fi

	fi

	if [[ ! -f $ZAZ_VM ]]; then
		printf "\e[31merror:\e[0m $ZAZ_VM does not exist.\n"
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
	printf "Usage:\n  \e[32m$0\e[0m [[\e[36mnum\e[0m] \e[36mopcode\e[0m] ...\n"
	printf "      \e[36mnum\e[0m: repeat the next test multiple times\n"
	printf "      \e[36mopcode\e[0m: the opcode to be tested\n"
	printf "valid opcodes are ("
	for code in `cat $op_h_file|grep -Eo '\{\"[a-z]+\"'|grep -Eo "[a-z]+"|tr '\n' ' '|sed 's: $::g'`; do
		printf "$coma\e[35m%s\e[0m" $code
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
	printf "\e[36mtesting $2\e[0m: "
	$YOUR_VM $DUMP_OPT $1 $2 > $YOUR_OUT_FILE && $OSX_CONTAINER $ZAZ_VM -d $1 $2 > $ZAZ_OUT_FILE
	if [[ $? -ne 0 ]]; then
		exit
	fi
	diff --suppress-common-lines -y $YOUR_OUT_FILE $ZAZ_OUT_FILE 2>/dev/null
	if [[ $? -ne 0 ]]; then
		printf "\e[31mFAIL!\e[0m\n"
		mv $2 $2.fail
		return 1
	else
		printf "\e[32mOK\e[0m\n"
		mv $2 $2.ok
		return 0
	fi
}

# prints the number of cycles consumed by the opcode given as parameter
get_op_cost()
{
	cat $op_h_file|grep "{\"$1\", "|tr -d ' \t'|sed -E 's:\{(((T_IND|T_DIR|T_REG|0)\|?)+,?){1,3}\},::g'|cut -d',' -f4
#	if [ $1 = "live" ]; then
#		echo "10"
#	elif [ $1 = "ld" ]; then
#		echo "5"
#	elif [ $1 = "st" ]; then
#		echo "5"
#	elif [ $1 = "add" ]; then
#		echo "10"
#	elif [ $1 = "sub" ]; then
#		echo "10"
#	elif [ $1 = "and" ]; then
#		echo "6"
#	elif [ $1 = "or" ]; then
#		echo "6"
#	elif [ $1 = "xor" ]; then
#		echo "6"
#	elif [ $1 = "zjmp" ]; then
#		echo "20"
#	elif [ $1 = "ldi" ]; then
#		echo "25"
#	elif [ $1 = "sti" ]; then
#		echo "25"
#	elif [ $1 = "fork" ]; then
#		echo "800"
#	elif [ $1 = "lld" ]; then
#		echo "10"
#	elif [ $1 = "lldi" ]; then
#		echo "50"
#	elif [ $1 = "lfork" ]; then
#		echo "1000"
#	elif [ $1 = "aff" ]; then
#		echo "2"
#	else
#		echo "0"
#	fi
}

# Generate test files and test the vm with them
test_opcode()
{
	./tester $1 > /dev/null
	if [[ $? -ne 0 ]]; then
		printf "\e[31merror:\e[0m '$1': invalid instruction\n"
		print_usage
		exit
	fi
	total=0
	passed=0
	for file in `find tests/$1 -type f -name "*.cor"|sort -n -t'/' -k3`
	do
		#get_op_cost $1
		compare_corewar `get_op_cost $1` $file
		if [[ $? -eq 0 ]]; then
			passed=$((passed+1))
		fi
		total=$((total+1))
	done
	rm -f $ZAZ_OUT_FILE
	rm -f $YOUR_OUT_FILE
	if [[ $passed -eq $total ]]; then
		printf "\e[32m"
	fi
	printf "passed %d/%d\e[0m" $passed $total
	if [[ $passed -eq $total ]]; then
		printf " Well done !"
	fi
	printf "\n"
}

# Startpoint
init_tests $1

for op in "$@"; do
	if [[ $op =~ ^[0-9]+$ ]] ; then
		loop=$op
	else
		while [[ $loop -gt 0 ]]; do
			test_opcode $op
			loop=$((loop-1))
		done
		loop=1
	fi
done
