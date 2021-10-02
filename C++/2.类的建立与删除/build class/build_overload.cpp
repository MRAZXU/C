#include <stdio.h>
//手动调用构造函数的重载
class Test
{
private:
    int m_value;
public:
   
    Test() 
    { 
        printf("Test()\n");
        m_value = 0;
    }
   
    Test(int v) 
    { 
        printf("Test(int v), v = %d\n", v);
        m_value = v;
    }
   
    int getValue()
    {
        return m_value;
    }
};

int main()
{
   //当避免自动调用的重载规则时，可以手动调用
    Test ta[3] = {Test(), Test(1), Test(2)}; 
    for(int i=0; i<3; i++)
    {
        printf("ta[%d].getValue() = %d\n", i , ta[i].getValue());
    }
    Test t = Test(100);
    printf("t.getValue() = %d\n", t.getValue());
    return 0;
}