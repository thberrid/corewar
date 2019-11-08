#!/bin/bash

res=0
count=0
while [[ $res -eq 0 ]]; do
	printf " test: $count\n"
	if [[ count -gt 2000 ]]; then
		printf "\e[32menought...\e[0m\n"
		exit 0
	fi
	./run.sh clear
	./tester $1 > /dev/null
	./corewar -a -v 31 "./tests/$1/4.cor" "./tests/$1/36.cor" "./tests/$1/21.cor" "./tests/$1/11.cor" > mout
	./zcorewar -a -v 31 "./tests/$1/4.cor" "./tests/$1/36.cor" "./tests/$1/21.cor" "./tests/$1/11.cor" > zout
	diff mout zout > /dev/null
	res=$?
	count=$((count+1))
	if [[ $res -eq 0 ]]; then
		printf "\e[A"
	else
		diff mout zout | head
	fi
done
