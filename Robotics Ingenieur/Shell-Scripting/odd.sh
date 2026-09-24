#! /bin/bash

a=1

while (( a < 100 )); do
    if (( a % 2 != 0 )); then
        echo "$a"
    fi
    ((a++))
done