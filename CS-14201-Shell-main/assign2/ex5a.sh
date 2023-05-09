filename=""
filepath=""

read -p "Enter file name : " filename

filepath=$(find ~/Desktop -type f -name $filename)

if [ -z $filepath ]; then
	echo "File not found!"
else
	echo "Lines =" $(wc -l $filepath)
	echo "Words =" $(wc -w $filepath)
fi
