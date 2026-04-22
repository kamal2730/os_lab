#!/bin/bash

file=$1
counter=1

while read -r line; do
    if [ $((counter % 2)) -ne 0 ]; then
        echo "$line"
    fi
    
    counter=$((counter + 1))
done < "$file"
