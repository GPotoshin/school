#!/bin/bash

make compare

a=$(./dif 0.1 1 10 0 10 0 10)
b=$(./dif 0.1 2 10 0 10 0 10)

c=$(./dif 0.00001 1 10 0 10 0 10)
d=$(./dif 0.00001 2 10 0 10 0 10)

./compare $a $b $c $d
