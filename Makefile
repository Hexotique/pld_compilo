GENERATED 		:= antlr4-src
GRAMMAR 		:= ifcc.g4
ANTLR4_BINDIR 	:= /usr/bin
ANTLR4_INCDIR 	:= /usr/include/antlr4-runtime
ANTLR4_LIBDIR 	:= /usr/lib
ANTLR4_FILES 	:= ifccBaseVisitor ifccLexer ifccVisitor ifccParser

EXE := ifcc
SRC_DIR := src
INC_DIR := include
OBJ_DIR := obj

SRC := $(wildcard $(SRC_DIR)/*.cpp)
OBJ := $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

CXX			:= clang++
CXXFLAGS	:= -g -c -std=c++11 -Wno-defaulted-function-deleted -Wno-unknown-warning-option
CPPFLAGS 	:= -I $(ANTLR4_INCDIR) -I $(GENERATED) -I $(INC_DIR)
LDFLAGS 	:= -g
LDLIBS 		:=

.PHONY: tests

all: dirs antlr $(EXE)

test:
	sh ./tests/test_if.sh

$(EXE): $(OBJ) $(ANTLR4_FILES:%=$(OBJ_DIR)/%.o)
	$(CXX) $(LDFLAGS) $^ $(ANTLR4_LIBDIR)/libantlr4-runtime.so -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

antlr: $(GRAMMAR)
	$(ANTLR4_BINDIR)/antlr4 -visitor -no-listener -Dlanguage=Cpp -o $(GENERATED) $<
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(GENERATED)/ifccBaseVisitor.cpp -o $(OBJ_DIR)/ifccBaseVisitor.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(GENERATED)/ifccLexer.cpp -o $(OBJ_DIR)/ifccLexer.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(GENERATED)/ifccVisitor.cpp -o $(OBJ_DIR)/ifccVisitor.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(GENERATED)/ifccParser.cpp -o $(OBJ_DIR)/ifccParser.o

dirs:
	mkdir -p $(OBJ_DIR)
	mkdir -p $(GENERATED)

clean:
	@sudo rm -rf $(EXE)
	@sudo rm -rf $(OBJ_DIR)
	@sudo rm -rf $(GENERATED)
	@rm -rf tests/pld-test-output
