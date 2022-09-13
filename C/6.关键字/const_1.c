#include <stdio.h>
//const让变量有了只读的性质(告诉编译器这个值不能出现在符号左边)
//修饰局部变量，分配到栈空间
//修饰全局变量，存储到只读存储区(gcc)
const int g_cc = 2;
int main()
{
    const int cc = 1;
    int* p = (int*)&cc;
    printf("cc = %d\n", cc);//1
    *p = 3;
    printf("cc = %d\n", cc);//3

    p = (int*)&g_cc;
    printf("g_cc = %d\n", g_cc);
    *p = 4;
    printf("g_cc = %d\n", g_cc);//只读存储区不能修改
    return 0;
}
/*
cc = 1
cc = 3
g_cc = 2
[1]    80 segmentation fault  ./a.out
*/