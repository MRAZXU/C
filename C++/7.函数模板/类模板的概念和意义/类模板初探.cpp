#include <iostream>
#include <string>

using namespace std;
//告诉编译器还是模板
template < typename T >
class Operator
{
public:
    T add(T a, T b)
    {
        return a + b;
    }
    T minus(T a, T b)
    {
        return a - b;
    }
    T multiply(T a, T b)
    {
        return a * b;
    }
    T divide(T a, T b)
    {
        return a / b;
    }
};
//类模板也是两次编译
//第二次不支持减法操作，所以需要对减法操作符重载
string operator-(string& l, string& r)
{
    return "Minus";
}

int main()
{
    Operator<int> op1;//必须显示指定类型
    cout << op1.add(1, 2) << endl;
    Operator<string> op2;
    cout << op2.add("D.T.", "Software") << endl;
    cout << op2.minus("D.T", "Software") << endl;//第二次编译就会有问题但可以重载操作符
    return 0;
}
