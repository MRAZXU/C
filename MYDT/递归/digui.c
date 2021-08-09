#include <stdio.h>
//47.3树形结构
void han_move(int n, char a, char b, char c)
{
    if( n == 1 )
    {//凡是递归必有出口
    //无限的递归必然导致系统崩溃，函数收敛
    //这里用的是（n-1）法
    //先分析递归次数，然后化解问题的规模，这里的特殊位置是n=2
    //很适合树形结构来分析
    //212
        printf("%c --> %c\n", a, c);
    }
    else
    {
        han_move(n-1, a, c, b);
        han_move(1, a, b, c);
        han_move(n-1, b, a, c);
    }
}

//47.2 斐波那契数列
int fac(int n)
{
    if( n == 1 )
    {
        return 1;
    }
    else if( n == 2 )
    {
        return 1;
    }
    else
    {
        return fac(n-1) + fac(n-2);
    }
    return -1;//充分考虑各种边界条件，是递归的重点
}

//47.1递归求字符串长度
int strlen_r(const char* s)
{
    if( *s )//"\0"默认为0
    {
        return 1 + strlen_r(s+1);
    }
    else
    {
        return 0;
    }
}

int main()
{
    /******47.3************/
    han_move(3, 'A', 'B', 'C');
    /******47.2************/
     printf("%d\n", fac(1));
    printf("%d\n", fac(2));
    printf("%d\n", fac(9));
 /******47.1************/
     printf("%d\n", strlen_r("abc"));
    printf("%d\n", strlen_r(""));
    return 0;
}