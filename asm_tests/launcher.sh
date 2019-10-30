#!/bin/zsh


# VARS

ASM_ORIGINAL=../documents/vm_champs/asm
ASM_NEW=../documents/vm_champs/asm
#ASM_NEW=../asm

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
	echo -e $2 $4
}


# clean previous tests trace

rm tmp/*.cor inputs/*.cor
clear

# launch tests

echo ""
for test_script in srcs/*; do
	echo "> "`echo $test_script | cut -d / -f 2`"\n"
	source $test_script
	echo "\n"
done
echo ""
