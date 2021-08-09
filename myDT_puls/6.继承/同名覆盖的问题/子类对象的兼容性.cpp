#include <iostream>
#include <string>

using namespace std;

class Parent
{
public:
    int mi;
    void add(int i)
    {
        mi += i;
    }
    void add(int a, int b)
    {
        mi += (a + b);
    }
};
class Child : public Parent
{
public:
    int mv;
    void add(int x, int y, int z)
    {
        mv += (x + y + z);
    }
};
int main()
{
    Parent p;
    Child c;
    
    p = c;
    
    Parent p1(c);//子类初始化父类
    
    
    Parent& rp = c;//父类指向子类对象
    Parent* pp = &c;//父类引用子类对象
    
    rp.mi = 100;
    rp.add(5);             // 没有发生同名覆盖?----不会因为指针访问退化成了父类对象
    rp.add(10, 10);        // 没有发生同名覆盖?----不会因为指针访问退化成了父类对象
    
    /* 为什么编译不过? */
    // pp->mv = 1000;
    // pp->add(1, 10, 100);
    //当使用父类指针（引用）指向子类时
    //子类对象退化为父类对象
    //只能访问父类定义的成元
    //可以直接访问被子类覆盖的同名成员
    
    return 0;
}