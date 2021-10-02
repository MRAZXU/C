#include <stdio.h>
#include <string.h>
//重载的意义：
//代码自注释
//对已有函数名进行扩展
char* strcpy(char* buf, const char* str, unsigned int n)
{
    return strncpy(buf, str, n);
}

int main()
{
    const char* s = "D.T.Software";
    char buf[8] = {0};//C语言中当buff太小了，就会内存越界
    
    //strcpy(buf, s);
    strcpy(buf, s, sizeof(buf)-1);
    
    printf("%s\n", buf);
    
    return 0;
}