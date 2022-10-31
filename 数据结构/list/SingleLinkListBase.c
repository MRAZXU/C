#include <SingleLinkListBase.h>

//创建链表
link* create_link(char * a)
{ 
    link *head;
    link *p=NULL;   //操作指针与链表的结构必须一致
    link *ele = NULL;
    int n=0;
    n=strlen(a);//获取数个数
    //为了避免段错误，在创建链表尽量不要套用函数
   if (NULL == ( p=head = (link*)malloc(sizeof(link))))  //对头结点申请空间
    fprintf(stderr, "malloc error\n"),     exit(1); 
   // p=create_link_empty(head);error
    for ( int i=0;i<n ;  i++) 
    {    
        if (NULL == (ele = (link*)malloc(sizeof(link)))) //后续节点申请空间
        fprintf(stderr, "malloc error\n"), exit(1); 
        ele->ch = a[i];
        p->next=ele;
        p=ele;//p指向末尾
    } 
    ele->next=NULL;
    return head;
} 
/*************链表操作****************************************/
//
//从头部插入节点
void insert_link_head(link *head,link  *new)
{
    new=(link*)malloc(sizeof(link));
    new->ch='A';
    new->next=head->next;
    head->next=new;
}
//从尾部插入节点
void insert_link_tail(link *head,link  *new)
{
    new=(link*)malloc(sizeof(link));
    new->ch='C';
    link *p=head;
    while(NULL!=p->next)
        p=p->next;//遍历到最后的节点
    p->next=new;
    new->next=NULL;
}
//中间插入节点
void insert_link_med(link *head,link  *new,int n)
{
    int i;
    link *p=head;
    new=(link*)malloc(sizeof(link));
    new->ch='B';
    for(i=0;i<n;i++)
        p=p->next;
    new ->next=p->next;
    p->next=new;
}
/**************************************************************************/


//删除指定位置的节点
void del_link_ele(link *head,int n)
{
    link *p=head;//这里p的最终位置是n前面的位置
    int i;
    for(i=1;i<n;i++)
    {
           p=p->next;
    if(NULL==p->next)
        printf("There is no point\n");
    }
    //1.将结点从链表中摘下来2.手动释放被删除节点
    link *del=p->next;
    p->next=p->next->next;
    free(del);
}
//删除整个链表=边遍历边删除（只适用于单向）
void del_them_all(link *head)
{
    link *p=head;
    while (NULL!=p->next)
    {
        link *del=p;
        p=p->next;
        free(del);
    }
}
//遍历
void print_link(link *head) 
{ 
    link  *p = head; 
    if (NULL == head->next) return;
    while (NULL!=p->next)
    { 
        p = p->next; 
     putchar(p->ch);     
    } 
    putchar('\n'); 
} 