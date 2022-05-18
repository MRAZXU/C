#include <stdio.h>
#include <string.h>
//指针数组：里面全是指针数组
//指针数组定义：char *a[3]
//数组指针定义：char (*p)[3]  or  typedef char Char[];Char[]*p
#define DIM(a) (sizeof(a)/sizeof(*a))
//const char* key指向的数据不变的指针的数组
int lookup_keyword(const char* key, const char* table[], const int size)
{
    int ret = -1;
    int i = 0;
    
    for(i=0; i<size; i++)
    {
        if( strcmp(key, table[i]) == 0 )
        {
            ret = i;
            break;
        }
    }
    return ret;
}
int main()
{

    const char* keyword[] = {
            "do",
            "for",
            "if",
            "register",
            "return",
            "switch",
            "while",
            "case",
            "static"
    };
    printf("%d\n", lookup_keyword("return", keyword, DIM(keyword)));//4
    printf("%d\n", lookup_keyword("main", keyword, DIM(keyword)));//-1

    return 0;
}