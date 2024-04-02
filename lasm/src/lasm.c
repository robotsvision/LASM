#include <lasm.h>

lm lmain(lu32 argc, lc* argv[]) {
    if (llibs_init() != L_OK) {
        return L_EXIT_FAILURE;
    }
    lcout(X("Это компилятор LASM."));
    return L_EXIT_SUCCESS;
}