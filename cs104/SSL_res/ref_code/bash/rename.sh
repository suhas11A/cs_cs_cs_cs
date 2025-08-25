#!/bin/bash

while read -r line; do
    arr=($line)
    mv ${arr[0]}.pdf ${arr[0]}_${arr[1]}.pdf 2>/dev/null
done < "$1"