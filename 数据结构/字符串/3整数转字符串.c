#include<stdio.h>
#include<string.h>
#define SWAP(p,q)  \
do {                                 \
            *p^=*q;             \
            *q^=*p;             \
            *p^=*q;             \
} while(0)

void strrev(char * str)
{
    int i,len;
    for(i=0,len=strlen(str);i<len/2;i++)
    {
        SWAP(&str[i],&str[len-i-1]);
    }
}

void int2str(int n,char *str)
{
    int j;
    if(NULL==str)
        printf("ERROR!\n");
    //加负号
    j=0;
    if(n<0)
    {
        n=-n;
        str[j++]='-';
    }
    while (n)
    {
        str[j++]=n%10+'0';//取余 从最低位取值
        n/=10;
    }
    str[j]='\0';
    if('-'==str[0])//颠倒数字字符串
    {
        strrev(str+1);  //别把负号搅进去了 
    }else
    {
        strrev(str);
    }
}
int main(void)
{
    char str[5];
    char *p=str;
    int num=-1234;
    int2str(num,str);
    printf("strlen=%ld\n",strlen(p));//strlen不包含'\0'strlen(p)=strlen(str)
     printf("strsize=%ld\n",sizeof(str));//没有'\0'
    //库函数中变现为自动忽略'\0' 实际是考虑了\
    所以自定义函数里面也因当考虑在内，封装时候看起来忽略了
    printf("str=%s\n",str);
}