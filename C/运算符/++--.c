#include <stdio.h> 
//在深入了解编译器行为后才能知道
//在平时尽量避免++--混合运算
int main()
{   
   // int i = 0;
    //++j++语义不明
    //int j = ++i+++i+++i;//直接报错
    int a = 1;
    int b = 4;
    int c = a+++b;
    
    int* p = &a;
    
    b = b/(*p);

    //printf("i = %d\n", i);
    //printf("j = %d\n", j);
    printf("a = %d\n", a);//2
    printf("b = %d\n", b);//2
    printf("c = %d\n", c);//5
      
    return 0;
}