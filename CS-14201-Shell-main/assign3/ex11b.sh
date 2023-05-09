gcd(){
    ans=1
    if [ $a -lt $b ]; then
        ((ans=a))
    else
        ((ans=b))
    fi
    while [ $ans -gt 0 ]
    do
      	if [ $((a%ans)) -eq 0 ] && [ $((b%ans)) -eq 0 ]; then
            break;
        fi
	((ans--))
    done
    return $ans
}

a=${1}
b=${2}
gcd $a $b
echo "HCF of "$a", "$b" = " $?
