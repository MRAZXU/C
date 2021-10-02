#include <stdio.h>
//因为没有返回值，构造函数确定已经执行了呢？（没有）
//构造函数return会怎样？立即结束构造函数--->初始化成半成品对象--->BUG
//二阶构造的方法就是可以解决半成品对象的
class Test
{
    int mi;
    int mj;
    //bool mStatus;//解决方案1
public:
    Test(int i, int j) : mStatus(false)
    {
        mi = i;
        return;
        //没有执行完，但是对象依旧可以诞生
        mj = j;
        mStatus = true;
    }
    int getI()
    {
        return mi;
    }
    int getJ()
    {
        return mj;
    }
    //解决方案1
    int status()
    {
        return mStatus;
    }
};

int main()
{  
    Test t1(1, 2);//所以就不能判断对象是否正确
    if( t1.status() )//解决方案1
    {
        printf("t1.mi = %d\n", t1.getI());
        printf("t1.mj = %d\n", t1.getJ());//return 出现了
    }
    return 0;
}
