#include <stdio.h>
//引用：一段已定义的变量的别名(相对于指针有更好的可读性实用性)
//最终本质就是指针，避开了C语言内存错误的风险
int main(int argc, char *argv[])
{
    //注意:类型一定要一致
    int a = 4;
    int& b = a;
    b = 5;
    printf("a = %d\n", a);//5
    printf("b = %d\n", b);//5
    printf("&a = %p\n", &a);//same
    printf("&b = %p\n", &b);//same
    return 0;
}