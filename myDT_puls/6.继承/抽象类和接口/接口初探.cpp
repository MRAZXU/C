#include <iostream>
#include <string>
//收发通信接口
using namespace std;

class Channel
{
public:
    virtual bool open() = 0;
    virtual void close() = 0;
    virtual bool send(char* buf, int len) = 0;
    virtual int receive(char* buf, int len) = 0;
};

int main()
{
    return 0;
}