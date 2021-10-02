#include <stdio.h>
//函数重载只与函数名，参数列表有关
//与返回值无关
//C++中通过函数名与函数参数确定函数调用\
而且这些同名的函数相互独立，有各自的函数地址
//C中只能通过函数名
int add(int a, int b)  // int(int, int)
{
    return a + b;
}

int add(int a, int b, int c) // int(int, int, int)
{
    return a + b + c;
}

int main()
{
    printf("%p\n", (int(*)(int, int))add);//0x564127e0064a
    printf("%p\n", (int(*)(int, int, int))add);//0x564127e0065e

    return 0;
}