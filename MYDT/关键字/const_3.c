#include <stdio.h>

const char* f(const int i)
{
    //i = 5;//error 只读性质
    return "Delphi Tang";
}

int main()
{
    const char* pc = f(0);//const char* 和 char* 
    printf("%s\n", pc);
    //pc[6] = '_';//error 
    printf("%s\n", pc);
    return 0;
}