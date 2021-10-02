#include <stdio.h>
/*************面试题**********************/
//下面输出什么为什么？
int main()
{
    char buf[10] = {0};
    char src[] = "hello %s";//这里面有一个空格'0'
    //将可变个参数src按照format格式化成字符串，然后将其复制到buf中
    //snprintf(buf, sizeof(buf), src);//后面没有格式化信息输出不确定hello AWA
    snprintf(buf, sizeof(buf), src,"ASA");
    printf("buf = %s\n", buf);
    return 0;
}
//这个函数掌握的还是不够透彻，不知道是不是重点