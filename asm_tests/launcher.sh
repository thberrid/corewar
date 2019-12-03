#!/bin/zsh


# VARS

ASM_ORIGINAL=../documents/vm_champs/asm
#ASM_NEW=../documents/vm_champs/asm
ASM_NEW=../asm

declare -i INDEX=1
declare -i SUCCESS
declare -l ERROR_MSG

# FNS

print_result ()
{
	if [ $3 -gt 0 ]; then
		echo -en "\e[1;32m$1 \e[0m"
	else
		echo -en "\e[1;31m$1 \e[0m"
	fi
	echo -e $2 "\e[1;31m$4\e[0m"
}

grep_logs () 
{
	SUCCESS=1
	#declare -l RETURN=`cat $VALG_LOGS | grep "definitely lost" | cut -d ' ' -f 7`
	declare -l RETURN=`cat $3 | grep $4 | cut -d ' ' -f $5`
	if [ $RETURN != $6 ]; then
		SUCCESS=0
	fi
	print_result $1 "$2 $4" $SUCCESS "($RETURN)"
}

# clean previous tests trace

clear
rm tmp/*.cor inputs/*.cor

# launch tests

for test_script in srcs/test_*; do
	echo "> "`echo $test_script | cut -d / -f 2`"\n"
	source $test_script
	echo ""
done
#rm tmp/*.cor inputs/*.cor
