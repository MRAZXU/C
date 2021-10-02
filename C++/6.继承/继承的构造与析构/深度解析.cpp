#include <iostream>
#include <string>
//子类构造顺序:先父母，后客人，再自己
using namespace std;

class Object
{
public:
    Object(string s)
    {
        cout << "Object(string s) : " << s << endl;
    }
};

class Parent : public Object
{
public:
    Parent() : Object("Default")
    {
        cout << "Parent()" << endl;
    }
    Parent(string s) : Object(s)
    {
        cout << "Parent(string s) : " << s << endl;
    }
};

class Child : public Parent
{
    Object mO1;
    Object mO2;
public:
    
    Child() : mO1("Default 1"), mO2("Default 2")
    {
        cout << "Child()" << endl;
    }
    //先父母 后客人
    Child(string s) : Parent(s), mO1(s + " 1"), mO2(s + " 2")
    {
        cout << "Child(string s) : " << s << endl;
    }
};

int main()
{       
    Child cc("cc");
    /*
Object(string s) : cc

Parent(string s) : cc

Object(string s) : cc 1
Object(string s) : cc 2

Child(string s) : cc
    
    */
    return 0;
}