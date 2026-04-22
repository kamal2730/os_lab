#!/bin/bash

find . -type f -name "*.txt" | while read -r file; do
    new_name="${file%.txt}.text"
    
    echo "Renaming: $file -> $new_name"
    mv "$file" "$new_name"
done

echo "Done!"
