#include <stdio.h>
//自动调用构造函数的重载
class Test
{
public:
    Test() 
    { 
        printf("Test()\n");
    }
    Test(int v) 
    { 
        printf("Test(int v), v = %d\n", v);
    }
};

int main()
{
    //按照重载规则自动重载构造函数
    Test t;      // 调用 Test()
    //同一种的不同表现形式
    Test t1(1);  // 调用 Test(int v)
    Test t2 = 2; // 调用 Test(int v)
    
    int i(100);
    printf("i = %d\n", i);
    
    return 0;
}