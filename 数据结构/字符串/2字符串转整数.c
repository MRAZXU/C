#include<stdio.h>
#include<string.h>
#define MAX_STR 5
//这类题就是'0'
int str2int(const char *str)
{
    int res,i;
    res=i=0;
    int  bPositive=1;//正负号
    if('-'==str[0])//判定符号
    {
        bPositive=0;
        ++i;
    }
    while (str[i]!='\0')
    {
        //res=res*10;一样的
        res=(res<<1)+(res<<3);//左移理解为乘法2^n 这里res*10
        res+=str[i++]-'0';//减去'0'
    }
    if(!bPositive)
        res=-res;
    return res;
}
int main(void)
{
    char str[MAX_STR];
    int num=0;
    printf("please input string:");
     fgets(str,MAX_STR+1,stdin);
    num=str2int(str);
    printf("num=%d\n",num);
}