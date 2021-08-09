#include <stdio.h>
//本质存储内存空间的变量别名
//*号的意义
//声明时：声明变量为指针
//使用时：指针指向的内存空间的值
int main()
{
    //这里的初始化就是申明
    int i = 0;
    int* pI;
    char* pC;
    float* pF;
    //取地址
    pI = &i;
    //取值
    *pI = 10;
    //指针也有大小 32位四字节 64位八字节
    printf("%p, %p, %d\n", pI, &i, i);
    printf("%ld, %ld, %p\n", sizeof(int*), sizeof(pI), &pI);
    printf("%ld, %ld, %p\n", sizeof(char*), sizeof(pC), &pC);
    printf("%ld, %ld, %p\n", sizeof(float*), sizeof(pF), &pF);
    
    return 0;
}
/*
0x7fffeb56b7dc, 0x7fffeb56b7dc, 10
8, 8, 0x7fffeb56b7e0
8, 8, 0x7fffeb56b7e8
8, 8, 0x7fffeb56b7f0
*/