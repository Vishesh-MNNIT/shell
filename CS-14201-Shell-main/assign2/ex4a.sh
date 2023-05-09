iter=1

read -p "Enter new dir : " dirname
mkdir $dirname
read -p "Enter number of files : " nfile

while [  $iter -le $nfile ]
do
	read -p "Enter file name : " filename
	cp $filename $dirname
	iter=$(( iter + 1 ))
done
