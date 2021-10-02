#include<stdio.h>
#include<string.h>

#define MAX_STR_LEN 128
/*宏定义实现*/
#define SWAP(p,q)  \
do {                                   \
            *p^=*q;              \
            *q^=*p;              \
            *p^=*q;             \
} while(0)
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
    printf("input string:");
    fgets(str,MAX_STR_LEN,stdin);//使用fgets可以避免内存越界
    for(i=0,len=strlen(str)-1;i<len/2;i++)//这里的-1是排除\n字符
    {
        //调试用
        //printf("str=%s,strlen=%ld.\n",str,strlen(str));
        //printf("i=%d,len=%d.\n",i,len);
        //两种方法
        //SWAP(&str[i],&str[len-i-1]);//这里是是次序调换所以注意数组开头为0，还有就是对应的为len-i-1 能调试最好
        swap(&str[i],&str[len-i-1]);
    }
    printf("reversed string:%s",str);

    return 0;
}
