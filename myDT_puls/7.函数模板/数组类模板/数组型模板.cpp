#include <iostream>
#include <string>
/********************面试题**********************/
using namespace std;

template
< typename T, int N >
void func()
{
    T a[N] = {0};
    
    for(int i=0; i<N; i++)
    {
        a[i] = i;
    }
    
    for(int i=0; i<N; i++)
    {
        cout << a[i] << endl;
    }
}
//递归---数值型模板参数
template
< int N >
class Sum
{
public:
    static const int VALUE = Sum<N-1>::VALUE + N;
};
//完全特化
template
< >
class Sum < 1 >
{
public:
    static const int VALUE = 1;
};


int main()
{
    cout << "1 + 2 + 3 + ... + 10 = " << Sum<10>::VALUE << endl;
    cout << "1 + 2 + 3 + ... + 100 = " << Sum<100>::VALUE << endl;
    
    return 0;
}

