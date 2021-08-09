#include <stdio.h>
//成员函数隶属于具体对象吗？
//不属于，他是被成员变量所共享
//因为函数存储在数据段，不能动态增加和删除
//所有成员变量共享一套成员函数
class Test
{
    int mi;
public:
    int mj;
    Test(int i);
    Test(const Test& t);
    int getMi();//y
    void print();
};

Test::Test(int i)
{
    mi = i;
}

Test::Test(const Test& t)
{
    mi = t.mi;
}
    
int Test::getMi()
{
    return mi;
}

void Test::print()
{
    printf("this = %p\n", this);
}

int main()
{
    Test t1(1);
    Test t2(2);
    Test t3(3);
    //隐藏了参数this指代当前对象
    printf("t1.getMi() = %d\n", t1.getMi());
    printf("&t1 = %p\n", &t1);
    t1.print();
    
    printf("t2.getMi() = %d\n", t2.getMi());
    printf("&t2 = %p\n", &t2);
    t2.print();
    
    printf("t3.getMi() = %d\n", t3.getMi());
    printf("&t3 = %p\n", &t3);
    t3.print();
    //类的成员函数中隐藏了一个this指针，指向当前成员变量的地址
    //这样就可以访问不同成员的变量，变量共享成员函数
    return 0;
}