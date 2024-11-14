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

run-lex:
	flex lex.ll
	g++ -g -o testlex testlex.o lex.yy.c
	./testlex test_lex.txt

mci: ast.o lex.yy.o parse.o lex.yy.c
	g++ -g ast.o lex.yy.o parse.o -o mci

lex.yy.o: lex.yy.c ast.o parse.cpp.h
	g++ -c -g lex.yy.c -o lex.yy.o
lex.yy.c:	lex.ll
	flex lex.ll
parse.cpp parse.cpp.h: parse.yy
	bison --verbose --debug -d parse.yy -o parse.cpp
parse.o:	parse.cpp ast.h 
ast.o:	ast.h ast.cpp

.cpp.o:
	-g++ -g -c $<

clean: 
	rm -f mci *.o lex.yy.c parse.cpp parse.cpp.h

