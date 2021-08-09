#include <iostream>
#include <string>
//class的本质：特殊的struct
using namespace std;

class A
{
    int i;
    int j;
    char c;
    double d;
public:
    void print()
    {
        cout << "i = " << i << ", "
             << "j = " << j << ", "
             << "c = " << c << ", "
             << "d = " << d << endl;
    }
};

struct B
{
    int i;
    int j;
    char c;
    double d;
};

int main()
{
    A a;
    
    cout << "sizeof(A) = " << sizeof(A) << endl;    // 20 bytes---成员函数并不会占用内存
    cout << "sizeof(a) = " << sizeof(a) << endl;    //20bytes
    cout << "sizeof(B) = " << sizeof(B) << endl;    // 20 bytes
    
    a.print();//乱码
    
    B* p = reinterpret_cast<B*>(&a);//重解释内存  a对象当做结构体B
    //当类退化为结构体时
    //权限关键字无效
    //可以通过内存地址直接访问成员变量
    p->i = 1;
    p->j = 2;
    p->c = 'c';
    p->d = 3;
    
    a.print();
    
    p->i = 100;
    p->j = 200;
    p->c = 'C';
    p->d = 3.14;
    
    a.print();
    
    return 0;
}
