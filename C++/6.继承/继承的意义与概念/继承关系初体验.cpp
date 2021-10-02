#include <iostream>
#include <string>

using namespace std;

class Parent
{
    int mv;
public:
    Parent()
    {
        cout << "Parent()" << endl;
        mv = 100;
    }
    void method()
    {
        cout << "mv = " << mv << endl;
    }
};
//
class Child : public Parent
{
public:
    void hello()
    {
        cout << "I'm Child calss!" << endl;
    }
};

int main()
{   
    //子类可以当做父类
    Child c;//Parent
    Parent p1=c;
    Parent p2;

    c.hello();
    c.method();
    
    p2=c;

    return 0;
}