#include "LinkListStatic.h"


void LinkListStatic(void)
{
    
    printf("***********LinkListStatic*************\n");

    StaticLinkList L;
    Status i;
    i=InitListSt(L);
    printf("初始化L后：L.length=%d 初始化状态：%d\n",ListLengthSt(L),i);

    i=ListInsertSt(L,1,'F');
    i=ListInsertSt(L,1,'E');
    i=ListInsertSt(L,1,'D');
    i=ListInsertSt(L,1,'B');
    i=ListInsertSt(L,1,'A');

    printf("\n在L的表头依次插入FEDBA后：\nL.data=");
    ListTraverseSt(L); 

    i=ListInsertSt(L,3,'C');
    printf("\n在L的“B”与“D”之间插入“C”后：\nL.data=");
    ListTraverseSt(L); 

    i=ListDeleteSt(L,1);
    printf("\n在L的删除“A”后：\nL.data=");
    ListTraverseSt(L); 

    printf("\n");

    return ;
}
