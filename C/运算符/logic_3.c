#include <stdio.h>

int main()
{
    printf("%d\n", !0);//1
    printf("%d\n", !1);//0
    printf("%d\n", !100);//0
    printf("%d\n", !-1000);//0
    
    return 0;
}