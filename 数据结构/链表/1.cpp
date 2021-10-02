#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int a[3]={1,2,3},*p=a;
    cout<<*(++p)<<" ";
    cout<<++(*p)<<endl;
    for(int i=0;i<3;i++)
    cout<<a[i]<<endl;
    return 0;
}
