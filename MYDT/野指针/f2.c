#include <stdio.h>
#include <string.h>
#include <malloc.h>
//
struct Student
{
    char* name;
    int number;
};
//这里返回了局部变量的首地址
//局部变量存于栈空间中
char* func()
{
    static char p[] = "D.T.Software";
    return p;
}

void del(char* p)
{
    printf("%s\n", p);
    free(p);
}

int main()
{
    //结构体成员指针未初始化
    struct Student s;
    char* p = func();
    strcpy(s.name, p); 
    s.number = 99;
    //分配的内存不够，
    p = (char*)malloc(5);
    strcpy(p, "D.T.Software");
    del(p);
    return 0;
}
