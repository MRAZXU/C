#include <stdio.h>
//内联函数：定义宏代码片段
//内联函数体直接插入函数调用的地方
//没有了函数调用的额外开销（压栈、跳转、返回）
//相较于C语言中的宏定义代码段，内联可以编译，参数检查，有返回类型
//所以能用内联尽量使用内联编译
#define FUNC(a, b) ((a) < (b) ? (a) : (b))


//一下是强制内联的结构
//__forceinline对于VC++相当于inline------->>>>>>VC++
//__attribute__((always_inline))------->>>>>>>g++
//内联声明必须在调用语句之前
inline 
int add_inline(int n);
int func(int a, int b);

int main(int argc, char *argv[])
{
     int a = 1;
    int b = 3;
    int c = FUNC(++a, b);
    int d=func(++a,b);
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("c = %d\n", c);
    printf("d = %d\n", d);
    /*********************************************/
    int r = add_inline(10);
    printf(" r = %d\n", r);

    return 0;
}
//内联函数申明必须和函数定义结合在一起，否则编译器直接忽略内联请求-->>\
编译器不一定满足请求。
//定义here 声明在上面
inline int add_inline(int n)
{
    int ret = 0;
    for(int i=0; i<n; i++)
    {
        ret += i;
    }
    return ret;
}
inline int func(int a, int b)
{
    return a < b ? a : b;
}
//但是内联编译也是有限制的
//不能过于庞大
//不能存在过多的条件判断
//不能有循环语句（取决于编译器）目前已经可以了
//不能对函数进行取地址的操作
//只要是不过与复杂就是