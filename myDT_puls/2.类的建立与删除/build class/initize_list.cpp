//初始化类中的const成员-----初始化列表
#include <stdio.h>
//注意！
//初始化列表先于构造函数的函数体执行
class Value
{
private:
    int mi;
public:
    Value(int i)
    {
        printf("i = %d\n", i);
        mi = i;
    }
    int getI()
    {
        return mi;
    }
};

class Test
{
private:
    const int ci;
    //成员的初始化顺序只与声明顺序相同
    Value m2;
    Value m3;
    Value m1;
public:
    //成员的初始化顺序与列表顺序无关----C++BUG点
    //const成员只能在初始化列表中指定初始值
    Test() : m1(1), m2(2), m3(3), ci(100)
    {
        printf("Test::Test()\n");
    }
    int getCI()
    {
        return ci;
    }
    int setCI(int v)
    {
        int* p = const_cast<int*>(&ci);
        
        *p = v;
    }
};


int main()
{
    Test t;
    printf("t.ci = %d\n", t.getCI());
    t.setCI(10);//只读变量通过指针赋值
    printf("t.ci = %d\n", t.getCI());
    
    return 0;
}