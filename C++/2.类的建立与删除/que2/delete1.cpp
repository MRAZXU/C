#include <stdio.h>
//单个对象创建时构造函数调用顺序
//1.调用父类的构造过程
//2.调用成员变量的构造函数
//3.调用类自身的构造函数
//！！！！！！构造函数与析构函数的调用顺序相反
//对于上面的，多个对象也是如此
class Member
{
    const char* ms;
public:
    Member(const char* s)
    {
        printf("Member(const char* s): %s\n", s);
        ms = s;
    }
    ~Member()
    {
        printf("~Member(): %s\n", ms);
    }
};

class Test
{   //只与声明顺序有关
    Member mA;
    Member mB;
public:
    Test() : mB("mB"), mA("mA")//和初始化列表一点关系也没有
    {
        printf("Test()\n");
    }
    ~Test()
    {
        printf("~Test()\n");
    }
};

Member gA("gA");//全局对象frist gA
int main()
{
    
    Test t;//mA
                //mB
                //Test()
                //析构与之相反
/*
Member(const char* s): gA
Member(const char* s): mA
Member(const char* s): mB
Test()
~Test()
~Member(): mB
~Member(): mA
~Member(): gA
*/
//结合前几节构造顺序的内容，
//对于栈对象和全局对象：最后构造的最先被析构
//堆空间的析构顺序与deleted使用相关
    return 0;
}