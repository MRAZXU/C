#include <SingleLinkListBase.h>

static void reverse_link(link *head)
{
    link *pele=NULL,*p=head->next;//p这时指向的是第一个有效节点
    if(NULL==p||NULL==p->next) return;
    //1.打破锁链
    head->next=NULL;//这时头结点指NULL,原有的链表开始重新构造
    while (NULL!=p)
    {
        //2.提取节点
        pele=p;//保存p这时的值，第一次以及后面的部分依然是连在一起的
        p=p->next;//前进
        //3.头节点插入
        pele->next=head->next;
        head->next=pele;    
    }
}
//逆序法2 就地逆置法(迭代法)
static link* reverse_link_recursion(link *head) //指向头结点
{ 

    //边界条件:链表为空直接返回，而p->next为空是递归基
    if(NULL==head||NULL==head->next) return head;
    link *new=reverse_link_recursion(head->next);
    if(0!=(head->ch))//p是否到了原来头节点的位置
    {
        head->next->next=head;//翻转链表的指向!
        head->next=NULL;//记得赋值NULL，防止链表错乱
        return new;//新链表头永远指向的是原链表的链尾
    }
    else
    {
        head->next=new;//建立新的头结点
        return head;
    }
}

void sigLinkTest(void) 
{ 
    link  *pH = NULL,*insert_ele=NULL,*newpH=NULL;
    char a[5]="12345";
    
    pH=create_link(a); 
    printf("original link is: "); 
    print_link(pH); 
   
    //头部插入，打印输出
    printf("insert after head, the link is: "); 
    insert_link_head(pH,insert_ele);
    print_link(pH); 
    //尾部插入，打印输出
    printf("insert behind tail, the link is: "); 
    insert_link_tail(pH,insert_ele);
    print_link(pH); 
    //中间第三个插入，打印输出
    insert_link_med(pH,insert_ele,3);
    printf("insert before 3, the link is: "); 
    print_link(pH); 
    //删除中间第四个
    del_link_ele(pH,4);
    printf("delete 4, the link is: "); 
    print_link(pH); 
    //逆序
    newpH=reverse_link_recursion(pH);
    reverse_link(pH); 
    printf("after reversed, the new link is: "); 
    print_link(newpH); 
    //删除整个链表
    del_them_all(pH);
    return ; 
}
