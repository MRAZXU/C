#include <iostream>
#include <string>
//利用操作符号重载实现智能指针
//智能指针智能指向堆空间
using namespace std;

class Test
{
    int i;
public:
    //构造函数
    Test(int i)
    {
        cout << "Test(int i)" << endl;
        this->i = i;
    }
    int value()
    {
        return i;
    }
    ~Test()
    {
        cout << "~Test()" << endl;
    }
};

class Pointer
{
    Test* mp;
public:
    Pointer(Test* p = NULL)
    {
        mp = p;
    }
    //拷贝构造函数中
    Pointer(const Pointer& obj)
    {
        //指针对空间所有权的传递，保证一片堆空间只有一个指针
        mp = obj.mp;//
        const_cast<Pointer&>(obj).mp = NULL;
    }
    Pointer& operator = (const Pointer& obj)//2
    {
        if( this != &obj )
        {
            delete mp;
            mp = obj.mp;
            const_cast<Pointer&>(obj).mp = NULL;
        }
        
        return *this;//1
    }
    /****************************************/
    Test* operator -> ()
    {
        return mp;
    }
    Test& operator * ()
    {
        return *mp;
    }
    /****************************************/
    //判断当前的智能指针是否为空
    bool isNull()
    {
        return (mp == NULL);
    }
    //析构函数
    ~Pointer()
    {
        delete mp;
    }
};

int main()
{
    //Pointer替代了指针的行为
    Pointer p1 = new Test(0);
    cout << p1->value() << endl;
    Pointer p2 = p1;
    cout << p1.isNull() << endl;
    cout << p2->value() << endl;
    
    return 0;
}
