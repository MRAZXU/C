
//宏常量的不是常量，只是字面量，不占用任何内存(与const区别)
//宏表达式
//下面的宏常量正确吗？
#define ERROR -1
#define PATH1 "D:\test\test.c"
#define PATH2 D:\test\test.c//对的
#define PATH3 D:\test\
test.c
//这里"|"变成了接续符
int main()
{
    int err = ERROR;//nt err = -1;
    char* p1 = PATH1;//char* p1 = "D:\test\test.c";
    char* p2 = PATH2;//char* p2 = D:\test\test.c;不会做语法检查，编译直接报错
    char* p3 = PATH3;//char* p3 = D:\test\;
}
//gcc -E define1.c -o define.i
/*
# 1 "define1.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 31 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 32 "<command-line>" 2
# 1 "define1.c"
# 9 "define1.c"
test.c

int main()
{
    int err = -1;
    char* p1 = "D:\test\test.c";
    char* p2 = D:\test\test.c;
    char* p3 = D:\test\;
}
*/