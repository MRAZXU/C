#include <stdio.h>
//枚举类型真正的常量
//默认规则，默认第一个赋值为0，默认下一个再前一个的基础上+1
enum
{
    ARRAY_SIZE = 10
};

enum Color
{
    RED    = 0x00FF0000,
    GREEN  = 0x0000FF00,
    BLUE   = 0x000000FF
};

void PrintColor(enum Color c)
{
    switch( c )
    {
        case RED:
            printf("Color: RED (0x%08X)\n", c);
            break;
        case GREEN:
            printf("Color: GREEN (0x%08X)\n", c);
            break;
        case BLUE:
            printf("Color: BLUE(0x%08X)\n", c);
            break;
    }
}

void InitArray(int array[])
{
    int i = 0;
    
    for(i=0; i<ARRAY_SIZE; i++)
    {
        array[i] = i + 1;
    }
}

void PrintArray(int array[])
{
    int i = 0;
    
    for(i=0; i<ARRAY_SIZE; i++)
    {
        printf("%d\n", array[i]);
    }
}


int main()
{
    enum Color c = GREEN;
    int array[ARRAY_SIZE] = {0};
    
    PrintColor(c);
    InitArray(array);
    PrintArray(array);
    
    return 0;
}