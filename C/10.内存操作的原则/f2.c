#include <stdio.h>
#include <malloc.h>
struct Demo
{
    char* p;
};
int main()
{
    //结构体成员未初始化
    struct Demo d1;
    struct Demo d2;
    char i = 0;
    for(i='a'; i<'z'; i++)
    {
        d1.p[i] = 0; 
    }
    d2.p = (char*)calloc(5, sizeof(char));
    printf("%s\n", d2.p);
    //26个字符不够 内存越界
    //这里还看不出来问题
    //但是在复杂的程序里面长时间的运行就有可能出现问题
    //BUG频发 吐血加班
    for(i='a'; i<'z'; i++)
    {
        d2.p[i] = i; 
    }
    free(d2.p);
    return 0;
}
