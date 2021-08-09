#include <stdio.h>
//C是合法的
//C++中定义多个同名的全局变量是非法的
int g_v;
//int g_v;
/******************************************/
struct Student
{
    const char* name;
    int age;
};
//C中会给未声明的类型添加为int，C++中直接非法 C++类型要求比C高
//C++任意标识符都要指明类型
//f(i)
void  f(int i)
{
    printf("i = %d\n", i);
}
//C中的面试题！***************************************]
//int f()与int f(void)的区别
//1.接受任意个参数2.不接受任何参数
//而C++中:1接受任意个参数f(...)2。不接受任何f()orf(void)
int g(...)
{
    return 5;
}
/******************************************/
int main(int argc, char *argv[])
{
    printf("Begin...\n");
    int c = 0;
    //所有变量都可以现用现定义，这里C99好像也支持了
    for(int i=1; i<=3; i++)
    {
        for(int j=1; j<=3; j++)
        {
            c += i * j;
        }
    }

    Student s1 = {"Delphi", 30};
    Student s2 = {"Tang", 30};
    
    f(10);
    
    printf("g() = %d\n", g(1,2,3,4,5));
    printf("c = %d\n", c);
    //C++可以获取register的地址，C却不能
    register int a = 0;
    printf("&a = %p\n", &a);
    printf("End...\n");
    
    return 0;
}