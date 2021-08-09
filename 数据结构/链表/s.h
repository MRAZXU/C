#ifndef  _S_H_
#define _S_H_

typedef struct link_tag
 { 
    char ch; 
    struct link_tag *next; 
} link;
void insert_link_head(link *head,link  *new);
void insert_link_tail(link *head,link  *new);
void insert_link_med(link *head,link  *new,int n);

link* create_link(char * a);
//删除指定位置的节点
void del_link_ele(link *head,int n);
//删除整个链表=边遍历边删除（只适用于单向）
void del_them_all(link *head);
//遍历
void print_link(link *head) ;

#endif // !_S_H_
