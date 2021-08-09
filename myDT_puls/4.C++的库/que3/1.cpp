#include <iostream>
#include <string>
//对赋值操作符重载
//当需要深拷贝时必须重载赋值操作符
using namespace std;

class Test
{
    int* m_pointer;
public:
    Test()
    {
        m_pointer = NULL;
    }
    Test(int i)
    {
        m_pointer = new int(i);
    }
    /*********************************************/
    Test(const Test& obj)
    {
        m_pointer = new int(*obj.m_pointer);
    }
    Test& operator = (const Test& obj)//返回值必须是引用，参数也得是constl类型
    {
        if( this != &obj )//自赋值
        {
            delete m_pointer;
            //如果地址不同进行深拷贝
            m_pointer = new int(*obj.m_pointer);
        }
        return *this;
    }
    /*********************************************/
    void print()
    {
        cout << "m_pointer = " << hex << m_pointer << endl;
    }
    ~Test()
    {
        delete m_pointer;
    }
};

int main()
{
    Test t1 = 1;//
    Test t2;//
    t2 = t1;
    //自赋值
    //t2=t2;
    t1.print();
    t2.print();
    
    return 0;
}