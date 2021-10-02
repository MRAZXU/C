#include <iostream>
#include <string>
//构造函数不可能成为虚函数
//析构函数可以成为虚函数
using namespace std;

class Base
{
public:
    Base()
    {
        cout << "Base()" << endl;
        func();
    }
    virtual void func() 
    {
        cout << "Base::func()" << endl;
    }
    virtual ~Base()//这里的应该是虚函数--工程上父类析构必须是虚函数
    {
        func();
        cout << "~Base()" << endl;
    }
};

class Derived : public Base
{
public:
    Derived()
    {
        cout << "Derived()" << endl;
        func();
    }
    virtual void func()
    {
        cout << "Derived::func()" << endl;
    }
    ~Derived()
    {
        func();
        cout << "~Derived()" << endl;
    }
};


int main()
{
    Base* p = new Derived();
    
    // ...
    
    delete p;
    
    return 0;
}
