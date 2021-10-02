//C++中的const得到了进化
#include <stdio.h>
//C中const的只读变量会分配存储空间
//C++中的可能会分配：1.const修饰的为全局的常量时2.&对const常量取地址

//C++中的const有作用域        define没有
void f()
{
    #define a 3
    const int b = 4;
}
void g()
{
    printf("a = %d\n", a);
    //printf("b = %d\n", b);//这里的b就是未定义了
}
int main()
{    
    /******************************************************/
    const int c = 0;
    int* p = (int*)&c;//对其常量取地址，分配存储空间
   printf("Begin...\n");
    *p = 5;
    //为了兼容c虽然分配了空间，但是不会去使用
     printf("c = %d\n", &c);//一样
    printf("c = %d\n", c);//0
    printf("*p = %d\n", p);//一样
    printf("*p = %d\n", *p);//5
    printf("End...\n");

    /*******************************************/
    const int A = 1;
    const int B = 2;
    int array[A + B] = {0};
    int i = 0;

        for(i=0; i<(A + B); i++)
    {
        printf("array[%d] = %d\n", i, array[i]);
    }
    
    f();
    g();
    /*
    array[0] = 0
    array[1] = 0
    array[2] = 0
    a = 3
    */

 
    return 0;
}