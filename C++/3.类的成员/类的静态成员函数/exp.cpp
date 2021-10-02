#include <stdio.h>

class Demo
{
private:
    int i;
public:
    int getI();
    static void StaticFunc(const char* s);//静态
    static void StaticSetI(Demo& d, int v);//静态
};

int Demo::getI()
{
    return i;
}

void Demo::StaticFunc(const char* s)
{
    printf("StaticFunc: %s\n", s);
}

void Demo::StaticSetI(Demo& d, int v)
{
    d.i = v;//可以通过对象名
   // i=v//静态成员函数不能直接访问成员变量
}

int main()
{
    //1通过类名直接调用静态成员函数
    Demo::StaticFunc("main Begin...");
    //2通过对象名调用静态成员函数
    Demo d; 
    d.StaticSetI(d, 10);
     printf("d=%d\n",d.getI());

     Demo::StaticSetI(d, 9);
    printf("d.i = %d\n", d.getI());
    Demo::StaticFunc("main End...");
    return 0;
}
