#include <stdio.h>
//数组指针：指向一个数组的指针
typedef int(AINT5)[5];
typedef float(AFLOAT10)[10];
typedef char(ACHAR9)[9];
int main()
{
    AINT5 a1;
    float fArray[10];
//如何定义一个数组指针
//第一种定义的方法如下：
//step1.typedef float(AFLOAT10)[10]为数组类型重命名
//step2.AFLOAT10* pf
    AFLOAT10* pf = &fArray;
    ACHAR9 cArray;
//OR！！：float (*pf)[10]    
//第二种定义的方法如下：
    char(*pc)[9] = &cArray;
    char(*pcw)[4] = cArray;


    int i = 0;
    printf("%ld, %ld\n", sizeof(AINT5), sizeof(a1));//20 20
    
    for(i=0; i<10; i++)
    {
        (*pf)[i] = i;
    }
    for(i=0; i<10; i++)
    {
        printf("%f\n", fArray[i]);//0.00000
    }
    printf("%p, %p, %p\n", &cArray, pc+1, pcw+1);
    //78-6f=10 73-6f=4 对应的就是数组元素的个数
    return 0;
}