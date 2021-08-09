#include <iostream>
#include <string>

using namespace std;

class Parent 
{
public:
    //子类继承默认调用只能调用父类的无参构造
    Parent()
    {
        cout << "Parent()" << endl;
    }
    Parent(string s)
    {
        cout << "Parent(string s) : " << s << endl;
    }
};

class Child : public Parent
{
public:
    Child()
    {
        cout << "Child()" << endl;
    }
    //只有通过显示调用才能调用父类构造函数
    Child(string s) : Parent(s)
    {
        cout << "Child(string s) : " << s << endl;
    }
};

int main()
{       
    Child c; 
    Child cc("cc");
    //调用的顺序始终是先去找父类有没有
    /*
    Parent() 隐式
    Child()
    Parent(string s) : cc 显示
    Child(string s) : cc
    */
    return 0;
}