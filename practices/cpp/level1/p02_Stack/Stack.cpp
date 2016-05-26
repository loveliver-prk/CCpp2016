#include "Stack.h"
Stack::Stack(int capbility)
{
    data=new int[capbility];
    this->capbility=capbility;
}
Stack::Stack()
{
    data=new int[100];
    capbility=100;
}
bool Stack::is_empty()
{
    return (head==tail);
}
bool Stack::is_full()
{
    return (head==capbility-1);
}
void Stack::push(int a)
{
    data[head]=a;
    head++;
}
int Stack::pop()
{
    head--;
    return data[head+1];
}
