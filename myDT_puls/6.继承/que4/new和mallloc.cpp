#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Test
{
    int* mp;
public:
    Test()
    {
        cout << "Test::Test()" << endl;
        
        mp = new int(100);
        
        cout << *mp << endl;
    }
    ~Test()
    {
        delete mp;
        
        cout << "~Test::Test()" << endl;
    }
};

int main()
{
    Test* pn = new Test;//专业针对对象
    //malloc不适用于对象的堆空间
    Test* pm = (Test*)malloc(sizeof(Test));//cstdlib支持的c库
    
    //free pn;会造成内存泄露
    //delete会触发析构
    delete pn;
    free(pm);
    //两种动态内存申请释放的使用不要混用
    return 0;
}