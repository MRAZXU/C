#include <stdio.h>

class TwoPhaseCons 
{
private:
    TwoPhaseCons() // 第一阶段构造函数
    { 
    }
    bool construct() // 第二阶段构造函数
    { 
        return true; 
    }
public:
    static TwoPhaseCons* NewInstance(); // 对象创建函数
};

TwoPhaseCons* TwoPhaseCons::NewInstance() 
{
   //这里有一个巧妙之处：创建函数是一个静态成员函数，调用构造函数时依然属于内部\
   所以可以访问private:
    TwoPhaseCons* ret = new TwoPhaseCons();
    // 若第二阶段构造失败，删除半成品对象返回 NULL    
    if( !(ret && ret->construct()) ) 
    {
        delete ret;
        ret = NULL;
    }
    
    return ret;
}


int main()
{
    //main不是类的成员函数
    //TwoPhaseCons* obj
    TwoPhaseCons* obj = TwoPhaseCons::NewInstance();//不能直接调用，main不是类的
    printf("obj = %p\n", obj);
    delete obj;
    return 0;
}
