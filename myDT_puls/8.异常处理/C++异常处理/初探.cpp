#include <iostream>
#include <string>

using namespace std;

double divide(double a, double b)
{
    const double delta = 0.000000000000001;
    double ret = 0;
    
    if( !((-delta < b) && (b < delta)) )
    {
        ret = a / b;
    }
    else
    {
        throw 0;//抛出异常----必被catch处理
        
    }
    
    return ret;
}

int main(int argc, char *argv[])
{    
    try//可能出现的异常
    {
        double r = divide(1, 0);
        cout << "r = " << r << endl;
    }
    //异常处理
    catch(...)//...用于处理所有类型的异常
    {
        cout << "Divided by zero..." << endl;
        //如果能够处理异常，程序继续执行
        //如果不能够处理，则函数停止执行，并返回
    }
    
    return 0;
}
