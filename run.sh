#!/bin/bash

TESTER=./tester
YOUR_VM=./corewar
ZAZ_VM=./documents/vm_champs/corewar

# The option to make your vm dump the memory as zaz's one do it (same format).
DUMP_OPT="-zdump"

YOUR_OUT_FILE=yout.dump
ZAZ_OUT_FILE=zout.dump

print_usage()
{
	echo "Usage:"
	echo "  $0 instruction"
}

compare_corewar()
{

	printf "\e[36mtesting $2\e[0m: "
	#echo "$YOUR_VM $DUMP_OPT $1 $2 > $YOUR_OUT_FILE"
	#echo "$ZAZ_VM -d $1 $2 > $ZAZ_OUT_FILE"
	diff --suppress-common-lines -y $YOUR_OUT_FILE $ZAZ_OUT_FILE 2>/dev/null
	if [[ $? -ne 0 ]]; then
		printf "\e[31mFAIL!\e[0m\n"
	else
		printf "\e[32mOK\e[0m\n"
	fi
}

get_op_cost()
{
	cat includes/op.h|grep "{\"$1\", "|tr -d ' \t'|sed -E 's:\{(((T_IND|T_DIR|T_REG|0)\|?)+,?){1,3}\},::g'|cut -d',' -f4
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

#sort -k
#
#	-k, --key=KEYDEF
#	-t --field-separator=SEP
#
#	KEYDEF  is F[.C][OPTS][,F[.C][OPTS]] for start and stop position, where F is
#			a field number and C a character position in the field; both are
#			origin 1, and the stop position defaults to the line's end.
#		If neither -t nor -b is in effect, characters in a field are counted
#			from the  beginning  of  the  preceding whitespace.
#		OPTS  is  one or more single-letter ordering options [bdfgiMhnRrV],
#			which override global ordering options for that key.
#		If no key is given, use the entire line as the key.
#		Use --debug to diagnose incorrect key usage.

if [[ -n $1 ]]; then
	make tester > /dev/null
	./tester $1 > /dev/null
	if [[ $? -ne 0 ]]; then
		printf "\e[31merror:\e[0m '$1': invalid instruction\n"
		print_usage
		exit
	fi
	for file in `find tests/$1 -type f -name "*.cor"|sort -n -t'/' -k3`
	do
		#get_op_cost $1
		compare_corewar `get_op_cost $1` $file
	done
else
	print_usage
fi
