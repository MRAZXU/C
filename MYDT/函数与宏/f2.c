#include <stdio.h>
#include <malloc.h>
//优点生成常规代码，封装简单的函数增加了代码的可读性 
//但是设计逻辑计算，复杂的代码不要这样
#define MALLOC(type, x)   (type*)malloc(sizeof(type)*x)
#define FREE(p)           (free(p), p=NULL)

#define LOG_INT(i)        printf("%s = %d\n", #i, i)
#define LOG_CHAR(c)       printf("%s = %c\n", #c, c)
#define LOG_FLOAT(f)      printf("%s = %f\n", #f, f)
#define LOG_POINTER(p)    printf("%s = %p\n", #p, p)
#define LOG_STRING(s)     printf("%s = %s\n", #s, s)

#define FOREACH(i, n)     while(1) { int i = 0, l = n; for(i=0; i < l; i++)
#define BEGIN             {
#define END               } break; } 

int main()
{
    int* pi = MALLOC(int, 5);
    char* str = "D.T.Software";
    
    LOG_STRING(str);
    
    LOG_POINTER(pi);
    
    FOREACH(k, 5)
    BEGIN
        pi[k] = k + 1;
    END
    
    FOREACH(n, 5)
    BEGIN
        int value = pi[n];
        LOG_INT(value);
    END
    
    FREE(pi);
    
    LOG_POINTER(pi);
    
    return 0;
}