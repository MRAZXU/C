#include <iostream>
#include <string>
/*****************构造函数抛出异常会怎样？********************************/
//用二阶去避免
using namespace std;

class Test
{
public:
    Test()
    {
        cout << "Test()" << endl;
        
        throw 0;
    }
    virtual ~Test()
    {
        cout << "~Test()" << endl;
    }
};


int main(int argc, char *argv[])
{
    Test* p = reinterpret_cast<Test*>(1);
    
    try
    {
        p = new Test();
    }
    catch(...)
    {
        cout << "Exception..." << endl;
    }
    
    cout << "p = " << p << endl;
    
    return 0;