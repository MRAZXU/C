#include <stdio.h>
#include <string.h>
//重点！！！字符串比较
int main()
{
    #define S1 "D.T.Software"
    #define S2 "D.T.Software"
//字符串比较不能用== 或者避免
//因为不同编译器对于==理解不同
//有的可能考虑地址是否一致

    if( S1 == S2 )
    {
        printf("Equal\n");
    }
    else
    {
        printf("Non Equal\n");
    }
    //正确的做法是调用函数
    if( strcmp(S1, S2) == 0 )
    {
        printf("Equal\n");
    }
    else
    {
        printf("Non Equal\n");
    }
    return 0;
}
