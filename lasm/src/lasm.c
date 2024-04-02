#include <lasm.h>

lm lmain(lu32 argc, lc* argv[]) {
    if (llibs_init() != L_OK) {
        return L_EXIT_FAILURE;
    }
    range(i, 0, 16) {
        range(j, 0, 16) {
            lccol(j, i);
            lcout(X("Hello!\n"));
        }
    }
    return L_EXIT_SUCCESS;
}