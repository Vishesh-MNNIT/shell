n=${1}

for (( i=1; i<=10; i++ ))
do
    echo $n "x" $i "=" $(( n * i ))
done
