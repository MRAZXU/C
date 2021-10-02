#include <stdio.h>
#include <string.h>
//C语言里不存在字符串
//是通过数组模拟字符串
int main()
{
  //{XXXXXX,'\0'}
  //"SSSSSS"里面自带'\0'
    char ca[] = {'H', 'e', 'l', 'l', 'o'};
   // char sa[] = {'W', 'o', 'r', 'l', 'd', '\0'};
    char ss[] = "Hello world!";
    char* str = "Hello world!";
    //2
    char b = "abc"[0];//a
    char c = *("123" + 1);//2
    char t = *"";//0
    //3
     char s[] = "Hello\0world";
    int i = 0;
/*****************************************************************/
//1
    printf("%s\n", ca);
    //printf("%s\n", sa);
    printf("%s\n", ss);
    printf("%s\n", str);
//2    
    printf("%c\n", b);
    printf("%c\n", c);
    printf("%d\n", t);
    printf("%s\n", "Hello");//Hello
    printf("%p\n", "World");//0x562e373a07a2
//3
    for(i=0; i<sizeof(s)/sizeof(char); i++)
    {
        printf("%c\n", s[i]);
    }
    printf("%s\n", s);
//strlen只认'\0'作为结束符
//第一个'\0'之前字符的个数
//char s[] = "Hello\0world";
    printf( "%ld\n", strlen(s) );
    printf( "%ld\n", strlen("123") );
    return 0;
}