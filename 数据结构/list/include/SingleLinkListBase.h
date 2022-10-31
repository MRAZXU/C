#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct link_tag
 { 
    char ch; 
    struct link_tag *next; 
} link;

//创建链表
link* create_link(char * a);

/*************链表操作****************************************/
//
//从头部插入节点
void insert_link_head(link *head,link *new);
//中间插入节点
void insert_link_med(link *head,link *new,int n);
//从尾部插入节点
void insert_link_tail(link *head,link *new);

//删除指定位置的节点
void del_link_ele(link *head,int n);

//删除整个链表=边遍历边删除（只适用于单向）
void del_them_all(link *head);

//遍历
void print_link(link *head);


