#include <iostream>
#include <string>
//使用函数对象------对函数调用操作符重载
//只能通过函数成员重载
//取代了函数指针
using namespace std;

class Fib
{
    int a0;
    int a1;
public:
    Fib()
    {
        a0 = 0;
        a1 = 1;
    }
    
    Fib(int n)
    {
        a0 = 0;
        a1 = 1;
        
        for(int i=2; i<=n; i++)
        {
            int t = a1;
            a1 = a0 + a1;
            a0 = t;
        }
    }
    //操作符重载
    int operator () ()
    {
        int ret = a1;
        a1 = a0 + a1;
        a0 = ret;
        return ret;
    }
};

int main()
{
    Fib fib;
    for(int i=0; i<10; i++)
    {
        cout << fib() << endl;
    }
    cout << endl;
    for(int i=0; i<5; i++)
    {
        cout << fib() << endl;
    }
    cout << endl;

    Fib fib2(10);
    for(int i=0; i<5; i++)
    {
        cout << fib2() << endl;
    }
    
    return 0;
}
