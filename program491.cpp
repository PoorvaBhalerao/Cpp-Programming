// Stack Data Structure
//prototype

#include<iostream>
using namespace std;

#pragma pack(1)
class Stacknode
{
    public:
        int data;
        Stacknode * next;

        Stacknode(int no)
        {
            data = no;
            next = NULL;
        }
};

class Stack
{
    private:
        Stacknode * first;
        int iCount;

    public:
        Stack();

        void push(int);             // InsertFirst
        int pop();                  // DeleteFirst
        int peep();

        void Display();
        int Count();
};

Stack :: Stack()
{
    cout<<"Object of Stack gets created\n";
    first = NULL;
    iCount = 0;
}

void Stack :: push(int no)               
{

}

int Stack :: pop()                 
{

}

int Stack :: peep()
{

}

void Stack :: Display()
{

}

int Stack :: Count()
{
    return this->iCount;
}



int main()
{
    Stack *stobj = new Stack();


    delete stobj;
    return 0;
}