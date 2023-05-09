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

max=${1}
echo "First $max Fibonacci numbers :"
fibo $max
