#include <iostream>
#include <string>
//++操作符能否被重载，重载后又如何区分前置++与后置++
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
    //成员函数进行操作符号重载
//前置就不要参数
    Test& operator ++ ()
    {
        ++mValue;
        return *this;
    }
    // 后置加一个占位符,返回值不是引用，返回当前值，符合i++的语义
    Test operator ++ (int)
    {
        Test ret(mValue);
        mValue++;
        return ret;
    }
};

int main()
{
    Test t(0);
    //这时前置与后置有了区别
    //前置的效率比后置高
    t++;
    ++t;
    return 0;
}
