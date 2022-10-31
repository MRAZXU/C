#include "LinkListSingle.h"

void LinkListSingle(void)
{        
    printf("***********LinkListSingle*************\n");
    LinkList L;
    ElemType e;
    Status i;
    int j,k;
    i=InitListSg(&L);
    printf("初始化L后：ListLength(L)=%d\n",ListLengthSg(L));
    for(j=1;j<=5;j++)
            i=ListInsertSg(&L,1,j);
    printf("在L的表头依次插入1～5后：L.data=");
    ListTraverseSg(L); 

    printf("ListLengthSg(L)=%d \n",ListLengthSg(L));
    i=ListEmptySg(L);
    printf("L是否空：i=%d(1:是 0:否)\n",i);

    i=ClearListSg(&L);
    printf("清空L后：ListLength(L)=%d\n",ListLengthSg(L));
    i=ListEmptySg(L);
    printf("L是否空：i=%d(1:是 0:否)\n",i);

    for(j=1;j<=10;j++)
            ListInsertSg(&L,j,j);
    printf("在L的表尾依次插入1～10后：L.data=");
    ListTraverseSg(L); 

    printf("ListLengthSg(L)=%d \n",ListLengthSg(L));

    ListInsertSg(&L,1,0);
    printf("在L的表头插入0后：L.data=");
    ListTraverseSg(L); 
    printf("ListLengthSg(L)=%d \n",ListLengthSg(L));

    GetElemSg(L,5,&e);
    printf("第5个元素的值为：%d\n",e);
    for(j=3;j<=4;j++)
    {
            k=LocateElemSg(L,j);
            if(k)
                    printf("第%d个元素的值为%d\n",k,j);
            else
                    printf("没有值为%d的元素\n",j);
    }
    

    k=ListLengthSg(L); /* k为表长 */
    for(j=k+1;j>=k;j--)
    {
            i=ListDeleteSg(&L,j,&e); /* 删除第j个数据 */
            if(i==ERROR)
                    printf("删除第%d个数据失败\n",j);
            else
                    printf("删除第%d个的元素值为：%d\n",j,e);
    }
    printf("依次输出L的元素：");
    ListTraverseSg(L); 

    j=5;
    ListDeleteSg(&L,j,&e); /* 删除第5个数据 */
    printf("删除第%d个的元素值为：%d\n",j,e);

    printf("依次输出L的元素：");
    ListTraverseSg(L); 

    i=ClearListSg(&L);
    printf("\n清空L后：ListLength(L)=%d\n",ListLengthSg(L));
    CreateListHeadSg(&L,20);
    printf("整体创建L的元素(头插法)：");
    ListTraverseSg(L); 
    
    i=ClearListSg(&L);
    printf("\n删除L后：ListLength(L)=%d\n",ListLengthSg(L));
    CreateListTailSg(&L,20);
    printf("整体创建L的元素(尾插法)：");
    ListTraverseSg(L); 


    return ;
}