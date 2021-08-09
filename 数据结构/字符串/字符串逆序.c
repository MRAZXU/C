#include<stdio.h>
#include<string.h>

#define MAX_STR_LEN 128
/*宏定义实现*/
#define SWAP(p,q)  do {*p^=*q;*q^=*p;*p^=*q;} while(0)
/*函数实现*/
void swap(char *p,char *q)
{
    char temp;
    temp =*p;
    *p = *q;
    *q = temp;
}
int main(void)
{
    char str[MAX_STR_LEN];
    int i,len;
    int MAX;
    printf("input string:");
    fgets(str,MAX,stdin);
    for(i=0,len=strlen(str)-1;i<len/2;++i)
    {
        //调试用
        printf("str=%s,strlen=%d.\n",str,strlen(str));
        printf("i=%d,len=%d.\n",i,len);
        SWAP(&str[i],&str[len-i-1]);
        //
    }
    printf("reversed string:%s",str);

    return 0;
}
