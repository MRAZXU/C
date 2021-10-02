#include <iostream>
#include <string>
//逻辑操作符重载后无法实现原生语义！！！
//建议：
//实际工程中尽力避免重载逻辑操作符
//通过重载比较操作符替代逻辑操作符
//使用成员函数代替逻辑操作符重载
//使用全局函数对逻辑操作符重载
using namespace std;

class Test
{
    int mValue;
public:
    Test(int v)
    {
        mValue = v;
    }
    int value() const
    {
        return mValue;
    }
};

bool operator && (const Test& l, const Test& r)
{
    return l.value() && r.value();
}

bool operator || (const Test& l, const Test& r)
{
    return l.value() || r.value();
}

Test func(Test i)
{
    cout << "Test func(Test i) : i.value() = " << i.value() << endl;
    
    return i;
}


int main()
{
    Test t0(0);
    Test t1(1);
//在重载的时候参数的顺序不一定
//逻辑运算的短路法则完全失效
    if( func(0) && func(1) )
    {
        cout << "Result is true!" << endl;
    }
    else
    {
        cout << "Result is false!" << endl;
    }
    
    cout << endl;
    
    if( func(0) || func(1) )
    {
        cout << "Result is true!" << endl;
    }
    else
    {
        cout << "Result is false!" << endl;
    }
    
    return 0;
}
