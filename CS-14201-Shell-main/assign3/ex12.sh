#!/bin/bash

# Define a 2D array as a matrix
matrix=(
    [0]="1 2 3"
    [1]="4 5 6"
    [2]="7 8 9"
)

# Get the number of rows and columns in the matrix
num_rows=${#matrix[@]}
num_cols=$(echo "${matrix[0]}" | wc -w)

# Define a new array to store the reversed matrix
reversed_matrix=()

# Loop through the matrix in reverse order and append the columns to the new array
for (( i=$num_cols-1; i>=0; i-- ))
do
    row=()
    for (( j=$num_rows-1; j>=0; j-- ))
    do
        row+=($(echo "${matrix[$j]}" | awk '{print $'$((i+1))'}'))
    done
    reversed_matrix+=("${row[*]}")
done

# Print the reversed matrix
for (( i=0; i<$num_cols; i++ ))
do
    for (( j=0; j<$num_rows; j++ ))
    do
        echo -n "${reversed_matrix[$i*$num_rows+$j]} "
    done
    echo ""
done