#include <stdio.h>
//本质是连续的存储段
//起始地址与长度必须有
int main()
{
    int a[5] = {1, 2};//没说明的默认初始化为0
    int b[] = {1, 2};//这里必须初始化，编译器才能分配好内存
    
    printf("a[2] = %d\n", a[2]);
    printf("a[3] = %d\n", a[3]);
    printf("a[4] = %d\n", a[4]);
    
    printf("sizeof(a) = %ld\n", sizeof(a));
    printf("sizeof(b) = %ld\n", sizeof(b));
    //一种求得数组元素个数的技巧！！！！！！！
    printf("count for a: %ld\n", sizeof(a)/sizeof(int));
    printf("count for b: %ld\n", sizeof(b)/sizeof(int));
    
    return 0;
}