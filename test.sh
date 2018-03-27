#!/bin/sh

a=0
rand="shuf -i 1-9 -n 1"

while [ $a -lt 50 ]
do
	rand_exec=`eval $rand`
	./lemipc `pwd` $rand_exec &
	a=`expr $a + 1`
done
