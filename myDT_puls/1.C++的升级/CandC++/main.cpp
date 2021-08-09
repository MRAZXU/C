#include <stdio.h>
//C++中调用C
//也可以C调用C++
#ifdef __cplusplus
extern "C" {//extern可以实现两者的相互调用
#endif

#include "add.h"

#ifdef __cplusplus
}
#endif


int main()
{
    int c = add(1, 2);
    printf("c = %d\n", c);
    return 0;
}