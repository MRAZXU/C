//这里的C兼容库是编译器厂商
#include <stdio.h>
#include <string.h>
//在不使用标准库的情况下重载左移操作符
//本程序还是在讨论操作符重载
const char endl = '\n';

class Console
{
public:
    //赋值重载
    Console& operator << (int i)
    {
        printf("%d", i);
        return *this;
    }
    Console& operator << (char c)
    {
        printf("%c", c);
        return *this;
    }
    Console& operator << (const char* s)
    {
        printf("%s", s);
        return *this;
    }
    Console& operator << (double d)
    {
        printf("%f", d);
        return *this;
    }
};
//命令行对象
Console cout;

int main()
{
    //重载后就可以连续传送
    cout << 1 << endl;
    cout << "D.T.Software" << endl;
    
    double a = 0.1;
    double b = 0.2;
    
    cout << a + b << endl;
    
    return 0;
}
