#!/bin/zsh


# VARS

ASM_ORIGINAL=../documents/vm_champs/asm
ASM_NEW=../documents/vm_champs/asm
#ASM_NEW=../asm


# FNS

print_result ()
{
	if [ $3 ]; then
		echo -en "\e[1;32m$1 \e[0m"
	else
		echo -en "\e[1;31m$1 \e[0m"
	fi
	echo -e $2
	echo "	$4"
}


# clean previous tests trace

rm tmp/*.cor
rm inputs/*.cor
clear

# test differents .s cases 
# compile then diff all .s files in ./inputs/

echo "---\n01 diff of .cor files\n"
declare -i INDEX=1
declare -i SUCCESS
declare -l ERROR_MSG
for filename in inputs/*.s; do
	SUCCESS=0
	ERROR_MSG=""
    [ -e "$filename" ] || continue
	$ASM_ORIGINAL $filename > /dev/null
	BTCODE_NAME=`echo $filename | cut -d / -f 2 | cut -d . -f 1`
	COR_FILE="inputs/$BTCODE_NAME.cor"
	if [ -e $COR_FILE ]; then
		COR_ORIGINAL="tmp/$BTCODE_NAME.cor"
		mv $COR_FILE $COR_ORIGINAL
		$ASM_NEW $filename > /dev/null
		COR_NEW=`echo $filename | cut -d . -f 1`".cor"
		if [ -e $COR_NEW ]; then
			DIFF=`diff $COR_NEW $COR_ORIGINAL`
			if [ "$DIFF" != "" ]; then
				SUCCESS=0
				ERROR_MSG="diff delta between the .cor files"
			else
				SUCCESS=1
			fi
		else
			SUCCESS=0
			ERROR_MSG="the .asm didn't compile"
		fi
	else	# else : the original ASM didn't compile
		$ASM_NEW $filename > /dev/null
		COR_NEW=`echo $filename | cut -d . -f 1`".cor"
		if [ -e $COR_NEW ]; then
			SUCCESS=0
			ERROR_MSG="the .asm shouldn't had compile"
		else
			SUCCESS=1
		fi
	fi
	print_result $INDEX $BTCODE_NAME $SUCCESS $ERROR_MSG
	let "INDEX+=1"
done

echo ""

echo "02 tests of wrong input cases"
# test wrong inputs
#	dev / null, dev / random, etc
#	not a .s file
#	unexistent filename
#	empty argument
# 	several filename
echo "---"
