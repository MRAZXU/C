#include <stdio.h>
//自动构造的自动析构。手动构造的必须手动析构
//尘归尘，土归土
class Test
{
    int mi;
public:
    Test(int i)
    {
        mi = i;
        printf("Test(): %d\n", mi);
    }
    ~Test()
    {
        printf("~Test(): %d\n", mi);
    }
};

int main()
{
    Test t(1);
    
    Test* pt = new Test(2);
    //这里只是对Test(2) 进行了析构 但是对于*pt指向的空间，并没有释放
    delete pt;
    
    return 0;
}