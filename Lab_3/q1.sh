#!/bin/bash

FILE=$1

if [ -d "$FILE" ]; then
    echo "It is a directory"
elif [ -f "$FILE" ]; then
    echo "It is a file"
else
    echo "Path does not exist"
fi
