#include <iostream>
#include <string>

using namespace std;
   //作用域与命名空间对于同名的处理一样
namespace A
{
    int g_i = 0;
}

namespace B
{
    int g_i = 1;
}

class Parent
{
public:
    int mi;//
    Parent()
    {
        cout << "Parent() : " << "&mi = " << &mi << endl;
    }
};

class Child : public Parent
{
public:
    int mi;//
    Child()
    {
        cout << "Child() : " << "&mi = " << &mi << endl;
    }
};

int main()
{
    Child c;
    
    c.mi = 100;    // mi 究竟是子类自定义的，还是从父类继承得到的？---子类的，父类被隐藏----同名覆盖
    //调用被隐藏的父类同名成员
   c.Parent::mi=1000;


    cout << "&c.mi = " << &c.mi << endl;
    cout << "c.mi = " << c.mi << endl;
    
    cout << "&c.Parent::mi = " << &c.Parent::mi << endl;
    cout << "c.Parent::mi = " << c.Parent::mi << endl;
    return 0;
}