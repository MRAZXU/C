#include <iostream>
#include <string>

using namespace std;

class Base
{
public:
    Base()
    {
        cout << "Base::Base()" << endl;
    }
    virtual ~Base()
    {
        cout << "Base::~Base()" << endl;
    }
};
class Derived : public Base
{
};

int main()
{
    //Base* p = new Base;//error
    Base* p = new Derived;
    //父类指针转化为子类指针（大前提---必须要有虚函数）
    Derived* pd = dynamic_cast<Derived*>(p);//不能子子类指针指向父类对象
    if( pd != NULL )
    {
        cout << "pd = " << pd << endl;
    }
    else
    {
        cout << "Cast error!" << endl;
    }
    
    delete p;
    return 0;
}