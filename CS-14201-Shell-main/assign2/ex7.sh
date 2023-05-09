x=1
y=1
ans=1

while getopts a:s:m:c:r op
do 
	x=${2}
	y=${3}
    case "${op}"
        in
		a)ans=$(( x + y ));;
		s)ans=$(( x - y ));;
		m)ans=$(( x * y ));;
		c)ans=$(( x / y ));;
		r)ans=$(( x % y ));;
		*)echo "Invalid Operator"
    esac

echo $ans
done
