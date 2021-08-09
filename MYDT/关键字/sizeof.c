#include <stdio.h>
//编译器内置的指示符
int f()
{
    printf("Delphi Tang\n");
    return 0;
}

int main()
{
    int var = 0;
    int size = sizeof(var++);
    printf("var = %d, size = %d\n", var, size);//0,4
    size = sizeof(f());
    printf("size = %d\n", size);//4这里是函数返回的值的大小
    return 0;
}