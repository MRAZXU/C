#include <stdio.h>
class Test
{
private:
    int i;
    int j;
public:
    int getI() { return i; }
    int getJ() { return j; }
    /*
    //统一的初始化解决方案（1）！！！！！！！！！！！！！！！！！！
    void initialize()
    {
        i = 1;
        j = 2;
    }
    */
   //统一的初始化解决方案（2）！！！！！！！！！！！！！！！！！！
   /********************构造函数****************************/
    Test()
    {
        printf("Test() Begin\n");
        i = 1;
        j = 2;
        printf("Test() End\n");
    }
};

Test gt;//全局
int main()
{
    //gt.initialize();----------------------------------->统一（1）！！！！！！！
    //如果不初始化静态存储区----->成员初始值为0
    printf("gt.i = %d\n", gt.getI());//0
    printf("gt.j = %d\n", gt.getJ());//0


    //如果不初始化栈空间----->成员初始值为随机值
    Test t1;
    //t1.initialize();----------------------------------->统一（1）！！！！！！！
    printf("t1.i = %d\n", t1.getI());//随机数
    printf("t1.j = %d\n", t1.getJ());//随机数


    //如果不初始化堆空间----->成员初始值为随机值
    Test* pt = new Test;//指针类型指向类（也是数据类型）也是合法
    // pt->initialize();----------------------------------->统一（1）！！！！！！！
    //这里只是一个巧合，其实也是随机的（随编译器）
    printf("pt->i = %d\n", pt->getI());
    printf("pt->j = %d\n", pt->getJ());
    delete pt;

    return 0;
}