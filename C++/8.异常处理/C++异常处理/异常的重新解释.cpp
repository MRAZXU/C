#include <iostream>
#include <string>
//catch里面可以抛出异常
//方便套娃的时候统一异常
//工程里面实际处理异常
using namespace std;

void Demo()
{
    try
    {
        try
        {
            throw 'c';
        }
        catch(int i)
        {
            cout << "Inner: catch(int i)" << endl;
            throw i;
        }
        catch(...)
        {
            cout << "Inner: catch(...)" << endl;
            throw;
        }
    }
    catch(...)
    {
        cout << "Outer: catch(...)" << endl;
    }
}

/*
    假设： 当前的函数式第三方库中的函数，因此，我们无法修改源代码
    
    函数名： void func(int i)
    抛出异常的类型： int
                        -1 ==》 参数异常
                        -2 ==》 运行异常
                        -3 ==》 超时异常
*/
void func(int i)
{
    if( i < 0 )
    {
        throw -1;
    }
    
    if( i > 100 )
    {
        throw -2;
    }
    
    if( i == 11 )
    {
        throw -3;
    }
    
    cout << "Run func..." << endl;
}
//调用第三方func统一异常
void MyFunc(int i)
{
    try
    {
        func(i);
    }
    catch(int i)
    {
        switch(i)//在catch中可以用switch再次对异常分类！！！！！！！
        {
            case -1:
                throw "Invalid Parameter";
                break;
            case -2:
                throw "Runtime Exception";
                break;
            case -3:
                throw "Timeout Exception";
                break;
        }
    }
}

int main(int argc, char *argv[])
{
    // Demo();
    
    try
    {
        MyFunc(11);
    }
    catch(const char* cs)//Myfunc内部的异常抛出到这里的catch
    {
        cout << "Exception Info: " << cs << endl;
    }
    
    return 0;
}
