#include <iostream>
#include <string>
//这里需要转换构造函数
//但是会引入隐式类型转换
//可以使用explicit关键字杜绝隐式类型转换
using namespace std;

class Test
{
    int mValue;
public:
    Test()
    {
        mValue = 0;
    }
    explicit Test(int i)//使用explicit关键字杜绝隐式类型转换
    {
        mValue = i;
    }
    Test operator + (const Test& p)
    {
        Test ret(mValue + p.mValue);
        return ret;
    }
    int value()
    {
        return mValue;
    }
};

int main()
{   
    Test t;
    t = static_cast<Test>(5);    // t = Test(5);
    Test r;
    r = t + static_cast<Test>(10);   // r = t + Test(10);
    cout << r.value() << endl;
    return 0;
}