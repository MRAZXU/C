#include <iostream>
#include <string>
//catch()
using namespace std;

void Demo1()
{
    try
    {   
        throw 'c';
    }
    //严格匹配，没有类型转换
    //有严格的顺序
    catch(char c)
    {
        cout << "catch(char c)" << endl;//匹配
    }
    catch(short c)
    {
        cout << "catch(short c)" << endl;
    }
    catch(double c)
    {
        cout << "catch(double c)" << endl;
    }
    //必须放在最后
    catch(...)
    {
        cout << "catch(...)" << endl;
    }
}

void Demo2()
{
    throw string("D.T.Software");
}

int main(int argc, char *argv[])
{    
    Demo1();
    
    try
    {
        Demo2();
    }
    catch(char* s)
    {
        cout << "catch(char *s)" << endl;
    }
    catch(const char* cs)
    {
        cout << "catch(const char *cs)" << endl;
    }
    catch(string ss)
    {
        cout << "catch(string ss)" << endl;//匹配
    }
    return 0;
}
