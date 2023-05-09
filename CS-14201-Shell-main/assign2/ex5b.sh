filename=${1}
filepath=""

filepath=$(find ~/Desktop -type f -name $filename)

if [ -z $filepath ]; then
	echo "File not found!"
else
	echo "Lines =" $(wc -l $filepath)
	echo "Words =" $(wc -w $filepath)
fi
