n=0
read -p 'Enter number n : ' n

for (( i=1; i<=10; i++ ))
do
	echo $n "x" $i "=" $(( n * i )) 
done
