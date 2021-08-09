#include <stdio.h>
//函数指针
/*******************面试题！！！************************************/
//如何使用C语言直接跳转到某个固定的地址开始执行
//利用函数指针
//typedef 函数返回值类型  *name(参数列表)
//定义1:typedef  typeoffunc name (para list)
//name*p=funcname
//定义2:type (*p)(para list)=funcname
typedef int(FUNC)(int);
int test(int i)
{
    return i * i;
}
void f()
{
    printf("Call f()...\n");
}
int main()
{
    FUNC* pt = test;//指向函数test的函数指针
    void(*pf1)() = f;//指向函数f的函数地址
    void(*pf)() = &f;
    printf("pf = %p\n", pf);
    //这里函数名类似于数组名
    //函数名==入口地址==函数指针指向函数名（入口地址）
    //f=&f
    printf("f = %p\n", f);
    printf("&f = %p\n", &f);
    pf();
    (*pf)();
    pf1(); 
    (*pf1)();
    printf("Function pointer call: %d\n", pt(2));
    
    return 0;
}