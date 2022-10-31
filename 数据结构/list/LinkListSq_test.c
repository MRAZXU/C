#include "LinkListSq.h"

void LinkListSq(void)
{
        
    printf("***********LinkListSq*************\n");
    SqList L;
    SqList Lb;
    
    SqElemType e;
    Status i;
    int j,k;
    i=InitListSq(&L);
    printf("初始化L后：L.length=%d\n",L.length);
    for(j=1;j<=5;j++)
            i=ListInsertSq(&L,1,j);
    printf("在L的表头依次插入1～5后：L.data=");
    ListTraverseSq(L); 

    printf("L.length=%d \n",L.length);
    i=ListEmptySq(L);
    printf("L是否空：i=%d(1:是 0:否)\n",i);

    i=ClearListSq(&L);
    printf("清空L后：L.length=%d\n",L.length);

    i=ListEmptySq(L);
    printf("L是否空：i=%d(1:是 0:否)\n",i);

    for(j=1;j<=10;j++)
            ListInsertSq(&L,j,j);
    printf("在L的表尾依次插入1～10后：L.data=");
    ListTraverseSq(L); 

    printf("L.length=%d \n",L.length);

    ListInsertSq(&L,1,0);
    printf("在L的表头插入0后：L.data=");
    ListTraverseSq(L); 
    printf("L.length=%d \n",L.length);

    GetElemSq(L,5,&e);
    printf("第5个元素的值为：%d\n",e);
    for(j=3;j<=4;j++)
    {
            k=LocateElemSq(L,j);
            if(k)
                    printf("第%d个元素的值为%d\n",k,j);
            else
                    printf("没有值为%d的元素\n",j);
    }
    

    k=ListLengthSq(L); /* k为表长 */
    for(j=k+1;j>=k;j--)
    {
            i=ListDeleteSq(&L,j,&e); /* 删除第j个数据 */
            if(i==ERROR)
                    printf("删除第%d个数据失败\n",j);
            else
                    printf("删除第%d个的元素值为：%d\n",j,e);
    }
    printf("依次输出L的元素：");
    ListTraverseSq(L); 

    j=5;
    ListDeleteSq(&L,j,&e); /* 删除第5个数据 */
    printf("删除第%d个的元素值为：%d\n",j,e);

    printf("依次输出L的元素：");
    ListTraverseSq(L); 

	//构造一个有10个数的Lb
	i=InitListSq(&Lb);
    for(j=6;j<=15;j++)
            i=ListInsertSq(&Lb,1,j);

	unionLSq(&L,Lb);

	printf("依次输出合并了Lb的L的元素：");
    ListTraverseSq(L); 

    return ;
}
