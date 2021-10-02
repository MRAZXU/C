#include <stdio.h>
#include <string.h>
//函数重载：同一函数名定义的不同函数
//重载的条件
//1.参数个数不同
//2.参数类型不同
//3.参数顺序不同
int func(int x)
{
    return x;
}
int func(int a, int b)
{
    return a + b;
}
int func(const char* s)
{
    return strlen(s);
}
/*************************************BUT!!!!*************************/
//这里就会出现二意性
int fund(int a, int b, int c = 0)
{
    return a * b * c;
}
int fund(int a, int b)
{
    return a + b;
}
/*************************************BUT!!!!*************************/
int main(int argc, char *argv[])
{
    printf("%d\n", func(3));
    printf("%d\n", func(4, 5));
    printf("%d\n", func("D.T.Software"));
    
   // int c = fund(1, 2);//error 出现了重载歧义\
   (是三个参数，还是两个参数 出现了个数的不确定性) 编译失败
    return 0;
}
