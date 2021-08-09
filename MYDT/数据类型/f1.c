#include <stdio.h>

typedef int INT32;
int main()
{
//typedef    
 INT32 i32;
 char c = -5;
 short s = 6;
 int i = -7;
  //取符号位的方法
printf("%d\n", ( (c & 0x80) != 0 ));
printf("%d\n", ( (s & 0x8000) != 0 ));
printf("%d\n", ( (i & 0x80000000) != 0 ));
printf("%d, %d\n", sizeof(INT32), sizeof(i32));
return 0;
}