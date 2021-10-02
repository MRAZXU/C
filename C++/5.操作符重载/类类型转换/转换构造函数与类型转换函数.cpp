#include <iostream>
#include <string>

using namespace std;

class Test;

class Value
{
public:
    Value()
    {
    }
    //转换构造与类型转换互相为逆
    //转换构造函数前需要加explicit
    //实际工程有type toType成员函数定义
    //QT
    /*
    QString str = "";
    int i = 0;
    double d = 0;
    short s = 0;

    str = "-255";
    i = str.toInt();
    d = str.toDouble();
    s = str.toShort();
    */
    explicit Value(Test& t)
    {
    }
};

class Test
{
    int mValue;
public:
    Test(int i = 0)
    {
        mValue = i;
    }
    int value()
    {
        return mValue;
    }
    operator Value()
    {
        Value ret;
        cout << "operator Value()" << endl;
        return ret;
    }
};

int main()
{   
    Test t(100);
    Value v = t;
    
    return 0;
}