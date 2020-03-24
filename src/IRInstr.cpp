#include "IRInstr.h"

void IRInstr::gen_asm(ostream &o)
{
    switch(op) {
        case 1:
            o << "assmm" <<endl;
        break;
    }
}