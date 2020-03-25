GENERATED 		:= antlr4-src
GRAMMAR 		:= ifcc.g4
ANTLR4_BIN	 	:= /usr/bin/antlr4
ANTLR4_LIB 		:= /usr/lib/libantlr4-runtime.so
ANTLR4_INCDIR 	:= /usr/include/antlr4-runtime
ANTLR4_FILES 	:= ifccBaseVisitor ifccLexer ifccVisitor ifccParser

EXE 		:= ifcc
SRC_DIR 	:= src
INC_DIRS 	:= include include/ast-nodes $(ANTLR4_INCDIR) $(GENERATED)
OBJ_DIR 	:= obj

AST_DIR		:= src/ast-nodes
AST_SRC		:= $(wildcard $(AST_DIR)/*.cpp)
AST_OBJ		:= $(AST_SRC:$(AST_DIR)/%.cpp=$(OBJ_DIR)/%.o)

SRC := $(wildcard $(SRC_DIR)/*.cpp)
OBJ := $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o) $(ANTLR4_FILES:%=$(OBJ_DIR)/%.o) $(AST_OBJ) 

CXX			:= clang++
CXXFLAGS	:= -g -c -std=c++11 -Wno-defaulted-function-deleted -Wno-unknown-warning-option
CPPFLAGS 	:= $(addprefix -I ,$(INC_DIRS))
LDFLAGS 	:= -g
LDLIBS 		:=

.PHONY: tests

all: dirs antlr $(EXE)

test:
	rm -rf ./tests/pld-test-output
	sh ./tests/test_if.sh

$(EXE): $(OBJ)
	$(CXX) $(LDFLAGS) $^ $(ANTLR4_LIB) -o $@

$(OBJ_DIR)/%.o: $(AST_DIR)/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

antlr: $(GRAMMAR)
	$(ANTLR4_BIN) -visitor -no-listener -Dlanguage=Cpp -o $(GENERATED) $<
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
