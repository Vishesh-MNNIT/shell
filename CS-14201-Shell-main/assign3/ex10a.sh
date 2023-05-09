function fibo(){
	i=0
    a=0
	b=1
	c=0
	echo $a
	echo $b
	for (( i=2; i<=max; i++ ))
	do
		(( c=a+b ))
		echo $c
		(( a=b ))
		(( b=c ))
	done
}

read -p "Enter a number : " max
echo "First $max Fibonacci numbers :"
fibo $max

