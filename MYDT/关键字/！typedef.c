#include <stdio.h>
/********************重要考点!**************************/
//用于给已存在的数据类型重新命名，本质上不能产生新的类型
//不能修饰unsigned和signed
typedef int Int32;
//typedef可以在typedef语句之后定义
//1.
struct _tag_point
{
    int x;
    int y;
};
typedef struct _tag_point Point;
//2.
typedef struct
{
    int length;
    int array[];
} SoftArray; 
//3.
typedef struct _tag_list_node ListNode;
struct _tag_list_node
{
    ListNode* next;
};

int main()
{
    Int32 i = -100;        // int 
    //unsigned Int32 ii = 0;
    Point p;               // struct _tag_point
    SoftArray* sa = NULL;   
    ListNode* node = NULL; // struct _tag_list_node*
    return 0;
}