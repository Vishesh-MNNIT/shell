n=0
file="/Users/souravpaul/shell_lab/endSem/ex3in.txt"
while IFS= read -r line
do
    n=$line 
done < "$file"

for (( i=1; i<=10; i++ ))
do
    echo $n "x" $i "=" $(( n * i ))
done


read number < number.txt

# Generate multiplication table
for (( i=1; i<=10; i++ ))
do
  result=$((number*i))
  echo "$number x $i = $result"
done


# if [ ! -f ex3in.txt ]; then
#   echo "File ex3in.txt not found."
#   exit 1
# fi

# while read num; do
#   echo "Multiplication table for $num:"
#   for i in {1..10}; do
#     echo "$num x $i = $((num*i))"
#   done
#   echo ""
# done < ex3in.txt
