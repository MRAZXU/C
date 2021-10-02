#include <stdio.h>
//函数入栈顺序---调用约定（调用协定）---多用于库调用库开发
//或者多语言互相调用------比如linuxC的开发
//原因是不同的编译器造成的入栈顺序问题，也就是f1的问题



//这一节的代码和上述的没啥关系。但也引出了另一个关于函数的秘密
//C语言中的可变参数
//问：如何将下面的函数改为可变参数的函数
float average(int array[], int size)
{
    int i = 0;
    float avr = 0;
    for(i=0; i<size; i++)
    {
        avr += array[i];
    }
    return avr / size;
}

int main()
{
    int array[] = {1, 2, 3, 4, 5};
    
    printf("%f\n", average(array, 5));
    
    return 0;
}