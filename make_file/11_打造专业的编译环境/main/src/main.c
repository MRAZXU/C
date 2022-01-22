#include <stdio.h>
#include "define.h"

extern void module_main();
extern void common();
int main()
{
    printf("Version: %s\n", VERSION);
    printf("main()::start main ...\n");
    
    common();
    module_main();
}
