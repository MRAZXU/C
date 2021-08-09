#include <stdio.h>
//回调函数
//回调机制与固定地址跳转都需要函数指针!
//回调机制
//1.调用者不知道何时调用哪一个
//2.被调用者不知道何时被调用，只知道需要完成的具体任务
//3.当事件发生时，调用者通过函数指针调用具体函数
typedef int(*Weapon)(int);
//调用者
void fight(Weapon wp, int arg)
{
    int result = 0;
    printf("Fight boss!\n");
    result = wp(arg);
    printf("Boss loss: %d\n", result);
}

int knife(int n)
{
    int ret = 0;
    int i = 0;
    for(i=0; i<n; i++)
    {
        printf("Knife attack: %d\n", 1);
        ret++;
    }
    
    return ret;
}

int sword(int n)
{
    int ret = 0;
    int i = 0;
    for(i=0; i<n; i++)
    {
        printf("Sword attack: %d\n", 5);
        ret += 5;
    }
    return ret;
}

int gun(int n)
{
    int ret = 0;
    int i = 0;
    for(i=0; i<n; i++)
    {
        printf("Gun attack: %d\n", 10);
        ret += 10;
    }
    return ret;
}

int main()
{
    fight(knife, 3);
    fight(sword, 4);
    fight(gun, 5);
    return 0;
}