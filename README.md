R C compiler with antlr4/c++

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

## Contributing
- Each feature to be implemented must have its own branch named `feature/FEATURE_TO_IMPLEMENT`. Contributors are to work on this branch and after completion and testing, create a pull request to the `master` branch.

## Features
Feature | Implemented
--- | :---:
Parses basic variable types (`char` and `int`) |  []
Handles comments in code | [X]
Handles variable declaration in the beginning of function blocks | []
Handles variable initialisation during declaration | []
Handles basic code blocks | []
Handles arithmetic expressions (+, -, *) | []
Handles bit-to-bit operators (`AND`, `OR`, `XOR`) | []

## Past project management (before the 27/03/20)

The first weeks were focused on discovering the subject and installing all the necessary components on our machines (Linux ubuntu, docker...).
Then, one part of the group focused on grammar while the other one concentrated on the "back" trying to advance the compilation, while implementing the symbol table and the abstract syntax tree.
Unfortunately we made the mistake of moving the "forehead" too far forward which led us to have to review the grammar afterwards.

## Future project management

- Now that a strong code foundation has been established and that the basic mechanisms and workflow are understood by all the members, the workload can be more adequately distributed.
-Each member will henceforth be given the task of implementing a new feature and will therefore have to write the corresponding back and front codes along with the necssary tests.
