#include <stdio.h>
//面试必考！！！！！！！！！！！！！！！！！！！
int main()
{
    //主要甄别意义与数值
    int a[5] = { 0 };
//数组名代表数组首元素的地址
    printf("a = %p\n", a);
//数组首地址
    printf("&a = %p\n", &a);
//数组首元素的地址
    printf("&a[0] = %p\n", &a[0]);
//a =&a=&a[0]
    return 0;
}
/*
a = 0x7fff4b3a91e0
&a = 0x7fff4b3a91e0
&a[0] = 0x7fff4b3a91e0
*/