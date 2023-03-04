#include <stdio.h>
#include "teste.h"
#include "consola.h"
#include <string.h>
#include <crtdbg.h>
#include <stdlib.h>
#define _CRTDBG_MAP_ALLOC

int main() {
    run_all_tests();

    meniu();

    _CrtDumpMemoryLeaks();
    return 0;
}
