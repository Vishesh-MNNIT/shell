dirname=${1}
mkdir $dirname
i=2

shift
for i in $@
do
	filename=$i
	cp "$filename" "$dirname/"
done



# Check if user provided directory argument
if [ $# -lt 2 ]; then
  echo "Usage: $0 <directory> <file1> <file2> ... <fileN>"
  exit 1
fi

# Get directory name from first argument
directory="$1"

# Create directory if it doesn't exist
if [ ! -d "$directory" ]; then
  mkdir "$directory"
fi

# Copy each file to the directory
shift
for file in "$@"
do
  cp "$file" "$directory/"
done

echo "Files copied successfully to directory $directory."
