#!/bin/bash

print_usage()
{
	echo "Usage:"
	echo "  $0 instruction"
}

compare_corewar()
{
	
}

if [[ -n $1 ]]; then
	make tester > /dev/null
	./tester $1 > /dev/null
	if [[ $? -ne 0 ]]; then
		printf "\e[31merror:\e[0m '$1': invalid instruction\n"
		print_usage
		exit
	fi
	for file in `find tests/$1 -type f -name "*.cor"`
	do
		echo "$file"
	done
else
	print_usage
fi
