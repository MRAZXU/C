#include <stdio.h>
//局部对象的构造顺序与程序执行流有关
class Test
{
private:
    int mi;
public:
    Test(int i)
    {
        mi = i;
        printf("Test(int i): %d\n", mi);
    }
    //深拷贝-----针对对象的逻辑进行拷贝
    Test(const Test& obj)
    {
        mi = obj.mi;
        printf("Test(const Test& obj): %d\n", mi);
    }
    
};

int main()
{
    int i = 0;
    Test a1 = i;
    while( i < 3 )
    {
        Test a2 = ++i;
    }
    if( i < 4 )//i=3
    {
        Test a = a1;//进入
    }
    else
    {
        Test a(100);//没有进入
    }
    return 0;
}