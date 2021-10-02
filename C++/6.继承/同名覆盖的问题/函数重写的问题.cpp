#include <iostream>
#include <string>
//函数重写是同名覆盖的一种情况
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
    
    void print()
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
    
    void print()
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
    return 0;
}