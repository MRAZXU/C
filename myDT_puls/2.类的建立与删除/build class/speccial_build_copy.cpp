#include <stdio.h>
//两种重要且特殊的特殊的构造函数\
（在没有设定时编译器默默生成对应的构造函数）
//无参构造函数

//拷贝构造函数---->对成员变量赋值
//参数为：const class_name&
//例如：  Test(const Test& t)
//深拷贝：拷贝后对象的物理状态相同
//浅拷贝：拷贝后对象的逻辑状态相同
//需要深拷贝的时候：
//成员指向动态内存空间
//成员打开外存文件
//使用了系统中的网络端口等等。。。。。
//所以原则：自定义的拷贝函数必须进行深拷贝
class Test
{
private:
    int i;
    int j;
    int* p;
public:
    int getI()
    {
        return i;
    }
    int getJ()
    {
        return j;
    }
    int* getP()
    {
        return p;
    }
    /**********************************************************/
    Test(const Test& t)
    {
        i = t.i;
        j = t.j;
        p = new int;
        
        *p = *t.p;
    }
    Test(int v)
    {
        i = 1;
        j = 2;
        p = new int;
        
        *p = v;
    }
    /**********************************************************/
    void free()
    {
        delete p;
    }
};

int main()
{
    //（在没有设定时编译器默默生成对应的构造函数）
    //但是编译器所提供的拷贝只有浅拷贝
    Test t1(3);
    Test t2(t1);
    
    printf("t1.i = %d, t1.j = %d, *t1.p = %d\n", t1.getI(), t1.getJ(), *t1.getP());
    printf("t2.i = %d, t2.j = %d, *t2.p = %d\n", t2.getI(), t2.getJ(), *t2.getP());
    /*
    t1.i = 1, t1.j = 2, *t1.p = 3
    t2.i = 1, t2.j = 2, *t2.p = 3
    */
    t1.free();
    t2.free();
    
    return 0;
}