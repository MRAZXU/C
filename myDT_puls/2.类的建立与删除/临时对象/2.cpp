#include <stdio.h>

class Test
{
    int mi;
public:
    Test(int i)
    {
        printf("Test(int i) : %d\n", i);
        mi = i;
    }
    Test(const Test& t)
    {
        printf("Test(const Test& t) : %d\n", t.mi);
        mi = t.mi;
    }
    Test()
    {
        printf("Test()\n");
        mi = 0;
    }
    int print()
    {
        printf("mi = %d\n", mi);
    }
    ~Test()
    {
        printf("~Test()\n");
    }
};
Test func()
{
    return Test(20);
}

int main()
{
    //C++编译器也在帮助你减少临时对象的产生
    //但是还要要避免
    Test t = Test(10); //1.生成临时对象2.用临时对象初始化3.用拷贝构造函数（X）
                                    //  编译器已经简化并杜绝了这个临时对象产生
                                    //直接等价于Test t=10;
                                    //同时提升了性能
    Test tt = func();  // ==> Test tt = Test(20); ==> Test tt = 20;
    
    t.print();
    tt.print();
    
    return 0;
}