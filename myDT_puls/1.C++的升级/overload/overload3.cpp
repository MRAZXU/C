#include <stdio.h>
#include <string.h>
//函数重载与函数指针
//将重载函数名赋值给函数指针时
//1、根据重载规则挑选与函数指针参数列表一致的候选者
//2、严格匹配!候选者的函数类型与函数指正类型
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
//声明函数指针，这里就要注意函数指针的类型
typedef int(*PFUNC)(int a);


int main(int argc, char *argv[])
{
    int c = 0;
    //根据函数指针与重载函数匹配关系可知，为第一个
    PFUNC p = func;
    c = p(1);   
    
    printf("c = %d\n", c);

    return 0;
}