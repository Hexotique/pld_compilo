docker run --rm -v $(pwd):/work eguerin/antlr4cpp bash -c "cd /work; make ANTLR4_INCDIR=/usr/include/antlr4-runtime ANTLR4_BIN=/bin/antlr4 ANTLR4_LIB=/lib/x86_64-linux-gnu/libantlr4-runtime.a"
