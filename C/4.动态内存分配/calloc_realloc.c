#include <stdio.h>
#include <malloc.h>
//calloc +初始化 将返回的内存空间初始化为0（不一定都为0 但肯定初始化了）的申请方式
//realloc修改原先分配的内存大小
#define SIZE 5
int main()
{
    int i = 0;
    int* pI = (int*)malloc(SIZE * sizeof(int));
    short* pS = (short*)calloc(SIZE, sizeof(short));
    for(i=0; i<SIZE; i++)
    {
        printf("pI[%d] = %d, pS[%d] = %d\n", i, pI[i], i, pS[i]);
    }
    printf("Before: pI = %p\n", pI);
    //扩展了两倍大小
    pI = (int*)realloc(pI, 2 * SIZE * sizeof(int));
    printf("After: pI = %p\n", pI);
    for(i=0; i<10; i++)
    {
        printf("pI[%d] = %d\n", i, pI[i]);
    }
    free(pI);
    free(pS);
    return 0;
}
/*
pI[0] = 0, pS[0] = 0
pI[1] = 0, pS[1] = 0
pI[2] = 0, pS[2] = 0
pI[3] = 0, pS[3] = 0
pI[4] = 0, pS[4] = 0
Before: pI = 0x55e660883260
After: pI = 0x55e6608836b0
pI[0] = 0
pI[1] = 0
pI[2] = 0
pI[3] = 0
pI[4] = 0
pI[5] = 0
pI[6] = 0
pI[7] = 0
pI[8] = 0
pI[9] = 0
*/