#include <iostream>
#include <string>

using namespace std;
/*
template < class T >//<typename T>
class Test
{
public:
    Test(T t) 
    { 
        cout << "t = " << t << endl;
    }
};

template < class T >
void func(T a[], int len)
{
    for(int i=0; i<len; i++)
    {
        cout << a[i] << endl;
    }
}

*/
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

int a = 0;

class Test_1
{
public:
    static const int TS = 1;
};

class Test_2
{
public:
    struct TS
    {
        int value;
    };
};

template
< class T >
void test_class()
{   
    //这里就问题了两个意思
    typename T::TS * a;        // 1. 通过泛指类型 T 内部的数据类型 TS 定义指针变量 a （推荐的解读方式）
                               // 2. 使用泛指类型 T 内部的静态成员变量 TS 与全局变量 a 进行乘法操作
}


int main(int argc, char *argv[])
{
    // test_class<Test_1>();
    test_class<Test_2>();
    
    return 0;
}