#include <stdio.h>
/*************！！面试题！！****************************/
//交换参数的位置
int swap(int* a, int* b)
{
    int c = *a;
    *a = *b;   
    *b = c;//*b=c=*a 这里的c不是指针哦
}
int main()
{
    int aa = 1;
    int bb = 2;
    printf("aa = %d, bb = %d\n", aa, bb);
    swap(&aa, &bb);
    printf("aa = %d, bb = %d\n", aa, bb);
    return 0;
}
