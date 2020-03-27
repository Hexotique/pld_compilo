C compiler with antlr4/c++

## Commands
- `make` compiles the parser. Libraries and include directories default to the values that work in an Arch Linux environment.
- `make test` runs the testing script provided. Runs all the tests provided in `tests/tests` directory.
- `make clean` deletes all generated files for compiliing the parser.

## Compilation scripts
- `compile_if.sh` is a script that compiles the project in linux machines available in INSA.
- `compile_ubuntu.sh` is a script that compiles the project in a different environment (a ubuntu where the antlr runtime had to be compiled manually).
- `compile_docker.sh` is a script to use if you are desperate. It compiles the project in a docker environment where antlr4 and its dependencies are properly installed.

## Quick start
- Linux machines with antlr4 installed locally should change the corresponding directories in the `Makefile` to correspond to local installation folders. All corresponding make commands will then work normally.
- If working with machines in INSA, run `sh ./compile_if.sh` in the terminal to compile the parser using corresponding configurations.
- On Windows machines, use Docker to avoid environment configurations. On PowerShell, run `sh ./compile_docker.sh` to compile the parser using a container.

## File Structure
- Header files are located in the `include` directory and their corresponding `.cpp` files are in the `src` directory.
- Files corresponding to nodes of the Abstract Syntax Tree (AST) are in the `ast-nodes` directory.

## Contributing
- Each feature to be implemented must have its own branch named `feature/FEATURE_TO_IMPLEMENT`. Contributors are to work on this branch and after completion and testing, create a pull request to the `master` branch.

## Features
Feature | Implemented
--- | :---:
Parses `int` variable type |  X
Parses `char` variable type |
Handles comments in code | X
Verifies that variables are declared before use | X
Verifies that no variable is declared twice | X
Handles variable declaration in the first line of block | X
Handles variable declaration anywhere in the block | X
Handles variable initialisation during declaration (e.g. `int a = 2`)| X
Handles `int` addition | X
Handles `int` substraction | X
Handles `int` multiplication | X
Handles `int` division | X
Handles bit-to-bit `AND` operator |
Handles bit-to-bit `OR` operator |
Handles bit-to-bit `XOR` operator |


## Past project management (until 27/03/20)

The first weeks were focused on discovering the subject and installing all the necessary components on our individual computers (Ubuntu, Docker, ANTLR4, etc...).
Then, part of the group focused on enhancing the grammar whilst the rest tackled the back-end of the compiler to advance the compilation, while implementing the symbol table and the abstract syntax tree.
Due to having made the choice of directly implementing the intermediate representation and control flow graphs, we took a lot more time to actually finish the link between the front-end and back-end to be able to see the results and have an end-to-end compilation.
This was then rectified and we ended up with a simple functioning compiler with the basic features specified as our mid-term objective.

## Future project management

Now that a strong code foundation has been established and that the basic mechanisms and workflow are understood by all the members, the workload can be more adequately distributed.
Each member will henceforth be given the task of implementing a new feature and will therefore have to write the corresponding back and front codes along with the necssary tests. Each member is hence expected to work from end to end when implementing a feature. We shall divide the hexanome to groups of 2 with each group in charge of a feature and organize sprints each week to keep up with the progress.
