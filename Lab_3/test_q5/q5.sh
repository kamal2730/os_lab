echo "Enter file extension (e.g., .txt) and destination folder name:"
read ext folder

mkdir -p "$folder"


cp *$ext "$folder/"

echo "Done! Files ending in $ext have been copied to $folder."
