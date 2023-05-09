#!/bin/bash

deg=${1}
a=${2}
b=${3}

pi=`echo "4*a(1)" | bc -l`
rad=`echo "$deg*($pi/180)" | bc -l`

echo "Scalar product of $a and $b = "
echo "c($rad)*$a*$b" | bc -l
