#include <stdio.h>
#include <malloc.h>
//破坏了程序的结果性
void func(int n)
{
    int* p = NULL;
    if(  n < 0 )
    {
        goto STATUS;
    }
    p = (int*)malloc(sizeof(int) * n);
    
STATUS:
    p[0] = n;    
    free(p);
}

int main()
{  
    printf("begin...\n");
    printf("func(1)\n");
    func(1);
    printf("func(-1)\n");
    func(-1);
    printf("end...\n");
    return 0;
}