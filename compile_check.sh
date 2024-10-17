#!/bin/bash

# Create exe directory
mkdir -p exe

# Compile and check
for num in {1..10}; do
    pattern="${num}_[0-9]*.cpp"
    c=0
    error_count=0
    for file in $pattern; do
        if [ -f "$file" ]; then
            c=$((c + 1))
            echo "Compiling: $file..."
            g++ "$file" ast.cpp -o "exe/$(basename "$file")-out"
            if [ $? -ne 0 ]; then
                echo "Compilation failed: $file"
                error_count=$((error_count + 1))
            else
                echo "Compilation success"
            fi
        fi
    done

    if [ $c -ne 0 ]; then
        if [ $error_count -ne 0 ]; then
            echo "Compilation failed for $error_count out of $c files for number $num"
            exit 1
        else
            echo "All compilations successful for $c files for number $num"
        fi
    fi
done
