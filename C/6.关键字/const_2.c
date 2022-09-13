#include <stdio.h>

const int g_array[5] = {0};

void modify(int* p, int v)
{
    *p = v;
}

int main()
{
    int const i = 0;
    const static int j = 0;
    int const array[5] = {0};

     //只有普通的局部变量可改变
    modify((int*)&array[0], 3);    // ok
    modify((int*)&i, 1);           // ok
    //static静态局部变量赋予了只读属性时，就不可变
    //modify((int*)&j, 2);           // error
    //全局变量也是不能的
    //modify((int*)&g_array[0], 4);  // error
    
    printf("i = %d\n", i);
    printf("j = %d\n", j);
    printf("array[0] = %d\n", array[0]);
    printf("g_array[0] = %d\n", g_array[0]);
    
    return 0;
}