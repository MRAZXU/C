#include <stdio.h>
//new的引用就是避免C语言中的动态内存申请引发的内存错误
//delete 替代了free
//new与mallocd的区别
//new是C++的一部分，malloc是C库提供的函数
//new以具体类型为单位进行内存分配，malloc是以字节为单位进行分配
//new在申请单个类型变量时可进行初始化，malloc不具备内存初始化的特性
int main()
{   
    //变量申请
    int* p = new int;
    *p = 5;
    *p = *p + 10;
    printf("p = %p\n", p);
    printf("*p = %d\n", *p);
    delete p;
    //数组申请
    p = new int[10];
    for(int i=0; i<10; i++)
    {
        p[i] = i + 1;
        printf("p[%d] = %d\n", i, p[i]);
    }
    delete[] p;
    //如果这里是delete p 则只释放了一个数组元素空间的数据
/***********申请的同时进行初始化***************************/
    int* pi = new int(1);
    // int* pa = new int[1];注意平时不要写成了申请数组 
    
    float* pf = new float(2.0f);
    char* pc = new char('c');

    printf("*pi = %d\n", *pi);
    printf("*pf = %f\n", *pf);
    printf("*pc = %c\n", *pc);
    
    delete pi;
    delete pf;
    delete pc;
    return 0;
}
