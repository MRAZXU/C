#include <stdio.h>

int f1()
{
    int r = 0;
    r++;
    return r;
}
int f2()
{
    static int r = 0;
    r++;
    return r;
}
int main()
{
    auto int i = 0;       // 显示声明 auto 属性，i 为栈变量(局部变量默认属性都是auto)
    //静态局部变量
    static int k = 0;     // 局部变量 k 的存储区位于静态区，作用域位于 main 中!
    //register直接操作寄存器，多用于嵌入式底层开发，
    //不能用于全局变量
    register int j = 0;   // 向编译器申请将 j 存储于寄存器而非内存中,这类请求不一定成功

    printf("%p\n", &i);
    printf("%p\n", &k);
    //printf("%p\n", &j);   // error 不能用&去访问寄存器的地址
    for(i=0; i<5; i++)
    {
        printf("%d\n", f1());
    }
    for(i=0; i<5; i++)
    {
        printf("%d\n", f2());
    }
    return 0;
}