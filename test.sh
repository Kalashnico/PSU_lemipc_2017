#!/bin/sh

a=1
rand="shuf -i 1-9 -n 1"

while [ $a -lt 51 ]
do
	echo "Launching player $a..."
	rand_exec=`eval $rand`
	./lemipc `pwd` $rand_exec &
	a=`expr $a + 1`
done

echo "All players launched."
