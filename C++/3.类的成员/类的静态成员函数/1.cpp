#include <stdio.h>

class Test
{
private:
    static int cCount;
public:
    Test()
    {
        cCount++;
    }
    ~Test()
    {
        --cCount;
    }
    //静态成员函数
    static int GetCount()
    {
        return cCount;
    }
};

int Test::cCount = 0;

int main()
{
    printf("count = %d\n", Test::GetCount());//0
    Test t1;
    Test t2;
    printf("count = %d\n", t1.GetCount());//2
    printf("count = %d\n", t2.GetCount());//2
    Test* pt = new Test();
    printf("count = %d\n", pt->GetCount());//3
    delete pt;
    printf("count = %d\n", Test::GetCount());//2
    return 0;
}