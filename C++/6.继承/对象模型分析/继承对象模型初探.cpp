#include <iostream>
#include <string>

using namespace std;

class Demo
{
protected:
    int mi;
    int mj;
public:
    //这里会多出一个虚函数指针+8字节
    virtual void print()
    {
        cout << "mi = " << mi << ", "
             << "mj = " << mj << endl;
    }
};

class Derived : public Demo
{
    int mk;
public:
    Derived(int i, int j, int k)
    {
        mi = i;
        mj = j;
        mk = k;
    }
    
    void print()
    {
        cout << "mi = " << mi << ", "
             << "mj = " << mj << ", "
             << "mk = " << mk << endl;
    }
};

struct Test
{
    void* p;
    int mi;
    int mj;
    int mk;
};

int main()
{
    cout << "sizeof(Demo) = " << sizeof(Demo) << endl; //16
    cout << "sizeof(Derived) = " << sizeof(Derived) << endl;  //24
    Derived d(1, 2, 3);
    //d对象的内存排布和Test的排布是一样的
    //对象的内存排列中父类成员在前子类成员在后
    Test* p = reinterpret_cast<Test*>(&d);
    cout << "Before changing ..." << endl;
    d.print();
    //用p指针改对象的值
    p->mi = 10;
    p->mj = 20;
    p->mk = 30;
    cout << "After changing ..." << endl;
    d.print();
    return 0;
}
