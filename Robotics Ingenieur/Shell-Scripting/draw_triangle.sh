#! /bin/bash
# Draw a triangle

lenght=0

read -p "Enter the lenght of the triangle: " lenght
read -p "Enter the character to use: " char

if [[ -z "$char" ]]; then
    char="*"
fi

for ((i = 0; i <= lenght; i++)); do
    for ((j = 0; j <= i; j++)); do
        echo -n "$char"
    done
    echo ""
done
