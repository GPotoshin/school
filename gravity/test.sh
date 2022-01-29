#!/bin/bash

make compare

a=$(./dif 0.01 1 10 0 10 0 1)
b=$(./dif 0.00001 1 10 0 10 0 1)

c=$(./dif 0.01 1 10 0 10 0 1)
d=$(./dif 0.00001 2 10 0 10 0 1)

echo
echo ">>> 1st method"
echo
./compare $a $b 0 10 1
echo
echo ">>> 2nd method"
echo
./compare $c $d 0 10 1
