#include <iostream>
#include <string>
//函数重写是同名覆盖的一种情况
//函数重写的问题
//虚函数virtual解决问题
using namespace std;

class Parent
{
public:
    int mi;
    virtual void add(int i)
    {
        mi += i;
    }
    virtual void add(int a, int b)
    {
        mi += (a + b);
    }
    virtual void print()
    {
        cout << "I'm Parent." << endl;
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
    
    void print()//这里也是虚函数 因为继承的关系可以不写
    {
        cout << "I'm Child." << endl;
    }
};
//函数重写
void how_to_print(Parent* p)
{
    p->print();
}

int main()
{
    Parent p;
    Child c;
    //本质
    //编译器只能根据指针的类型判断所指向的对象
    //根据赋值兼容原则，编译器认为父类指针指向的是父类对象
    //所以只能调用父类定义的同名函数
    how_to_print(&p);    // Expected to print: I'm Parent.
    how_to_print(&c);    // Expected to print: I'm Child.
    /*
I'm Parent.
I'm Parent.
    */
   //如何解决？
    //虚函数-----函数重写离不开虚函数
    /*
    I'm Parent.
I'm Child.
    */
    return 0;
}