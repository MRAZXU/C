#include <stdio.h>
//注意站位参数的声明也是可以使用默认参数
int func(int x, int = 0);

int main(int argc, char *argv[])
{
    printf("%d\n", func(1));
    printf("%d\n", func(2, 3));
    
    return 0;
}
//占位参数
//为了兼容C的不规范写法
int func(int x, int)
{
    return x;
}
/*********面试题！！！***********************/
//下面申明等价吗？void func()    void func(void)
//c语言中不等价 1.接收人意 2.不接受
//C++中等价