# receive one arg
num=$1

pattern="${num}_[0-9]*.cpp"

compile_command="g++"

# if num is 5, then check "g++ 5_1.cpp ast.cpp", "g++ 5_2.cpp ast.cpp"....
c=0
error_count=0
for file in $pattern; do
    c=$((c + 1))
    echo "Compiling: $file..."
    $compile_command "$file" ast.cpp -o "exe/$(basename "$file")-out"
    if [ $? -ne 0 ]; then
        echo "Compilation failed: $file"
        error_count=$((error_count + 1))
    else
        echo "Compilation success"
    fi
done

if [ $error_count -ne 0 ]; then
    echo "Compilation failed for $error_count files"
else
    echo "All Compilation success for $c files"
fi
