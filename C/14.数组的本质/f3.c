#include <stdio.h>
//这一部分也是细节
int main()
{
    int a[5] = {0};
    int b[2];
    int* p = NULL;
    
    p = a;
    printf("a = %p\n", a);
    printf("p = %p\n", p);
    printf("&p = %p\n", &p);
    printf("sizeof(a) = %ld\n", sizeof(a));
    printf("sizeof(p) = %ld\n", sizeof(p));
   /*
    a = 0x7ffd9ef5bd10
    p = 0x7ffd9ef5bd10 指针指向的数据
    &p = 0x7ffd9ef5bd00 指针的地址
    sizeof(a) = 20
    sizeof(p) = 8
   */
    printf("\n");
//数组名可以看作常量指针但不是指针更不能等同于指针
    p = b;
    printf("b = %p\n", b);
    printf("p = %p\n", p);
    printf("&p = %p\n", &p);
    printf("sizeof(b) = %ld\n", sizeof(b));
    printf("sizeof(p) = %ld\n", sizeof(p));
    /*
    b = 0x7ffd9ef5bd08
    p = 0x7ffd9ef5bd08
    &p = 0x7ffd9ef5bd00
    sizeof(b) = 8
    sizeof(p) = 8
    */
   //数组名可以看作常量指针但不是指针更不能等同于指针
   // b = a;
  
    return 0;
}
