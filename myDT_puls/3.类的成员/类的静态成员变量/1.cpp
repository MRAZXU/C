#include <stdio.h>

class Test
{
private:
    //int mCount;//每个成员各有一套
    //声明静态成员变量
     static int cCount;
    //静态成员变量也是有访问等级的
    //静态成员变量存储在类的外部
public:
    Test() 
    {
        cCount++;
    }
    ~Test()
    {
        --cCount;
    }
    int getCount()
    {
        return cCount;
    }
};
//！！！需要在类的外部进行定义
//静态成员变量定义
int Test::cCount = 0;

Test gTest;
int main()
{
    Test t1;
    Test t2;
    
    printf("count = %d\n", gTest.getCount());
    printf("count = %d\n", t1.getCount());
    printf("count = %d\n", t2.getCount());
    
    return 0;
}