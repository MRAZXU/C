#include <stdio.h>
#define RESET(p, len)          \
    while( len > 0 )           \
        ((char*)p)[--len] = 0

#define _ADD_(a, b) a + b
#define _MUL_(a, b) a * b
#define _MIN_(a, b) ((a) < (b) ? (a) : (b))

void reset(void* p, int len)
{
    while( len > 0 ) 
        ((char*)p)[--len] = 0;
}

int main()
{
    int array[] = {1, 2, 3, 4, 5};
    int len = sizeof(array);
    int i = 0;
    int n = 1;
    int m = 10;

    reset(array, len) ;
    for(i=0; i<5; i++)
    {
        printf("array[%d] = %d\n", i, array[i]);
    }
//三目最爱和宏定义考
    printf("%d\n", _MUL_(_ADD_(1, 2), _ADD_(3, 4)));//1+2*3+4=11
    printf("%d\n", _MIN_(n++, m));//(1++<10?1++:10)=2 


    return 0;
}