#!/bin/bash

if [ -z "$1" ]; then
    echo "Informe o arquivo que deve ser construído!"
    exit 1
fi

FILE=$1
OUTPUT="${FILE%.c}.out"

gcc -o "$OUTPUT" "$FILE"

if [ $? -eq 0 ]; then
    ./$OUTPUT
else
    echo "Erro na compilação."
fi

rm -rf ./$OUTPUT
