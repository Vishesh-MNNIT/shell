#!/bin/bash

read -p "Enter angle in degree : " deg
read -p "Enter a : " a
read -p "Enter b : " b

pi=`echo "4*a(1)" | bc -l`
rad=`echo "$deg*($pi/180)" | bc -l`

echo "Scalar product of $a and $b = "
echo "c($rad)*$a*$b" | bc -l
