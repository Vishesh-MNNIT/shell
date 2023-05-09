dirname=""
dirpath=""

read -p "Enter directory name : " dirname
dirpath=$(find ~/Desktop -type d -name $dirname)

if [ -z $dirpath ]; then
    echo "Directory not found!"
else
	ls $dirpath
fi
