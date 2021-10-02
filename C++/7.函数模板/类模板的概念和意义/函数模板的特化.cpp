#include <iostream>
#include <string>

using namespace std;
//特化是类模板提出的概念-----有部分特化以及完全特化
//函数模板只支持完全特化
template
< typename T1, typename T2 >
class Test
{
public:
    void add(T1 a, T2 b)
    {
        cout << "void add(T1 a, T2 b)" << endl;
        cout << a + b << endl;
    }
};

/*
template
<  >
class Test < void*, void* >    // 当 T1 == void* 并且 T2 == void* 时
{
public:
    void add(void* a, void* b)
    {
        cout << "void add(void* a, void* b)" << endl;
        cout << "Error to add void* param..." << endl;
    }
};
*/
//
class Test_Void
{
public:
    void add(void* a, void* b)
    {
        cout << "void add(void* a, void* b)" << endl;
        cout << "Error to add void* param..." << endl;
    }
};
/******************************************************************************/
//函数模板只支持完全特化
//部分
template
< typename T >
bool Equal(T a, T b)
{
    cout << "bool Equal(T a, T b)" << endl;
    
    return a == b;
}
//完全
template
< >
bool Equal<double>(double a, double b)
{
    const double delta = 0.00000000000001;
    double r = a - b;
    
    cout << "bool Equal<double>(double a, double b)" << endl;
    
    return (-delta < r) && (r < delta);
}
//函数重载
//浮点数不能精确判定相等
bool Equal(double a, double b)
{
    const double delta = 0.00000000000001;
    double r = a - b;
    
    cout << "bool Equal(double a, double b)" << endl;
    
    return (-delta < r) && (r < delta);
}

int main()
{  
    cout << Equal( 1, 1 ) << endl;//优先使用全局函数
    cout << Equal<>( 0.001, 0.001 ) << endl;//放弃全局函数，只考虑函数模板
    
    return 0;
}