//让专业的人做专业的事
//class 替代struct 
//将类的实现与定义分开
#include <stdio.h>
#include "Operator.h"

int main()
{
    Operator op;
    double r = 0;
    
    op.setOperator('/');
    op.setParameter(9, 3);
    
    if( op.result(r) )
    {
        printf("r = %lf\n", r);
    }
    else
    {
        printf("Calculate error!\n");
    }
    
    return 0;
}