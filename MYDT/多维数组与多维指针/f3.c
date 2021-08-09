#include <stdio.h>
#include <malloc.h>
/**********************面试题！！！****************************/
//动态申请二维数组内存空间
//考点在二维数组名上
//int a[5]  a类型为int*
//int a[2][5] a 类型为int(*)[5]
int** malloc2d(int row, int col)
{
    int** ret = NULL;
    if( (row > 0) && (col > 0) )
    {
        int* p = NULL;
        ret = (int**)malloc(row * sizeof(int*));
        p = (int*)malloc(row * col * sizeof(int));
        if( (ret != NULL) && (p != NULL) )
        {
            int i = 0;
            for(i=0; i<row; i++)
            {
                ret[i] = p + i * col;
            }
        }
        else
        {
            free(ret);
            free(p);
            ret = NULL;
        }
    }
    return ret;
}

void free2d(int** p)
{
    if( *p != NULL )
    {
        free(*p);
    }
    free(p);
}

int main()
{
    int** a = malloc2d(3, 3);
    int i = 0;
    int j = 0;
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            printf("%d, ", a[i][j]);
        }
        printf("\n");
    }
    free2d(a);
    return 0;
}
//尝试写个三维的