#include <iostream>
#include <string>
//逗号操作符重载----工作中也不要用---实属废物
using namespace std;

class Test
{
    int mValue;
public:
    Test(int i)
    {
        mValue = i;
    }
    int value()
    {
        return mValue;
    }
};

//这里和逻辑操作符一样全员函数不要用成员函数
//返回值为Test&引用 参数为const

Test& operator , (const Test& a, const Test& b)
{
    return const_cast<Test&>(b);//凸显逗号表达式的属性
}

Test func(Test& i)
{
    cout << "func() : i = " << i.value() << endl;
    
    return i;
}

int main()
{   
    Test t0(0);
    Test t1(1);
    Test tt = (func(t0), func(t1));         // Test tt = func(t1);
    
    cout << tt.value() << endl; // 1
    /*
    func() : i = 1
    func() : i = 0
    1
    违反了逗号表达式的运算顺序
    */
    return 0;
}