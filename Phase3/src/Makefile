TARGET = mycomp
all = $(TARGET)
CC = g++
CFLAGS = -lfl `llvm-config --cxxflags --cppflags mcjit native --ldflags --libs core` -ltinfo -lpthread -ldl
FLAGS = -w -Wno-deprecated -g -std=c++11 -o
NAME = compiler

all: $(TARGET)
$(TARGET): phase1 programdefs.cpp programdef.h
	$(CC) $(FLAGS) $(NAME) lex.yy.c parser.tab.cpp programdefs.cpp $(CFLAGS)

phase1: parser.ypp scanner.l
		bison -d parser.ypp
		flex scanner.l

clean:
	rm -f *.c *.tab.* *.output compiler
