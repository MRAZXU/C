//用户又又又来了
//需求：每次调用都要出现斐波那契数列项，不能有全局变量
//静态局部变量
#include <iostream>
#include <string>

using namespace std;

int fib()
{
    static int a0 = 0;
    static int a1 = 1;
    int ret = a1;
    a1 = a0 + a1;
    a0 = ret;
    return ret;
}

int main()
{
    for(int i=0; i<10; i++)
    {
        cout << fib() << endl;
    }
    cout << endl;
    for(int i=0; i<5; i++)
    {
        cout << fib() << endl;
    }
    return 0;
}
//缺点：
//一旦开始就无法重来
//函数是全局函数，无法多次独立使用
//无法指定某个具体的数列项作为初始值
