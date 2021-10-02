#include <iostream>
#include <string>

using namespace std;
//兼具宏代码块函数优点--------泛型编程
//函数模板
//tempalte---告诉编译器开始泛型编程   typename---T是一个泛指类型
template < typename T >
void Swap(T& a, T& b)
{
    T c = a;
    a = b;
    b = c;
}
//选择排序
template < typename T >
void Sort(T a[], int len)
{
    for(int i=0; i<len; i++)
    {
        for(int j=i; j<len; j++)
        {
            if( a[i] > a[j] )
            {
                Swap(a[i], a[j]);
            }
        }
    }
}

template < typename T >
void Println(T a[], int len)
{
    for(int i=0; i<len; i++)
    {
        cout << a[i] << ", ";
    }
    
    cout << endl;
}

int main()
{
    int a[5] = {5, 3, 2, 4, 1};
    
    Println(a, 5);
    Sort(a, 5);
    Println(a, 5);
    
    string s[5] = {"Java", "C++", "Pascal", "Ruby", "Basic"};
    
    Println(s, 5);
    Sort(s, 5);
    Println(s, 5);
    
    return 0;
}