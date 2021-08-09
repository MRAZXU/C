#include <stdio.h>
//指针加法
int main()
{
    int a[5] = {0};
    int* p = NULL;
    
    printf("a = 0x%X\n", (unsigned int)(a));
    printf("a + 1 = 0x%X\n", (unsigned int)(a + 1));
    //+1指的是一个指针长度+1
    //标准为：p+n======(unsigned int)(p)+n*sizeof(*p)
    printf("p = 0x%X\n", (unsigned int)(p));
    printf("p + 1 = 0x%X\n", (unsigned int)(p + 1));
    
    return 0;
}