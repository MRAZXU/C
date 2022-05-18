#include <stdio.h>
//一位数组：int a[5]---形参---退化int *a
//二维数组：int a[2][3]---形参---退化int (*a)[3]数组指针  还需要一个指向它的指针
//二维数组退化为数组指针 这个指针指向这个二维数组，如果哦要访问其元素，还需要一个指向这个指针的指针
//但是指针数组退化为二维指针
void access(int a[][3], int row)
{
    int col = sizeof(*a) / sizeof(int);
    int i = 0;
    int j = 0;
    printf("sizeof(a) = %ld\n", sizeof(a));//a退化为一个指针
    printf("sizeof(*a) = %ld\n", sizeof(*a));//*a指向一个a[3]的数组4X3=8
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            printf("%d\n", a[i][j]);
        }
    }
    printf("\n");
}
void access_ex(int b[][2][3], int n)//指向为[1][2][3]数组的指针
{
    int i = 0;
    int j = 0;
    int k = 0;
    printf("sizeof(b) = %ld\n", sizeof(b));//指针大小8字节
    printf("sizeof(*b) = %ld\n", sizeof(*b));//2X3X4=24
    for(i=0; i<n; i++)
    {
        for(j=0; j<2; j++)
        {
            for(k=0; k<3; k++)
            {
                printf("%d\n", b[i][j][k]);
            }
        }
    }
    printf("\n");
}
int main()
{
    int a[3][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};
    int aa[2][2] = {0};
    int b[1][2][3] = {0};
    
    access(a, 3);//8 12
    //aa在函数里变成a[2][3]
    access(aa, 2);//8 12
    access_ex(b, 1);//8 24 [2][2]-->[2][3]
    access_ex(aa, 2);//8 24[1][2][3]-->[2][2][3]
    
    return 0;
}
