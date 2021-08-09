#include <iostream>
#include <string>
//自动推到类型时，类型必须严格匹配
//显示类型指定时，可以进行隐式类型转换
//swap(<int> &a,T&b),左边那个就是显示指定
using namespace std;

class Test
{
    Test(const Test&);
public:
    Test()
    {
    }
};

template < typename T >
void Swap(T& a, T& b)
{
    T c = a;
    a = b;
    b = c;
}

typedef void(FuncI)(int&, int&);
typedef void(FuncD)(double&, double&);
typedef void(FuncT)(Test&, Test&);

int main()
{
    FuncI* pi = Swap;    // 编译器自动推导 T 为 int
    FuncD* pd = Swap;    // 编译器自动推导 T 为 double
    
    //FuncT* pt = Swap;    // 编译器自动推导 T 为 Test
    
    //pi和pd的地址不一样，内部隐藏了两个SWAP函数
    
    cout << "pi = " << reinterpret_cast<void*>(pi) << endl;
    cout << "pd = " << reinterpret_cast<void*>(pd) << endl;
   // cout << "pt = " << reinterpret_cast<void*>(pt) << endl;
    
    return 0;
}