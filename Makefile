# run the report generator
run-reportgen:
	./utils/reportgen

# compile the report generator
compile-reportgen:
	g++ -o utils/reportgen utils/reportgen.cpp

# format all files for submission
format:
	clang-format -i -style=file $(shell find . -name "*.cpp" -o -name "*.h")

# # check all files for compilation errors
# check:
# 	sh check.sh