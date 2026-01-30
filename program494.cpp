///////////////////////////////////////////////////////////////////////////////
//              Final code of Stack using generic approach
///////////////////////////////////////////////////////////////////////////////


#include<iostream>
using namespace std;

#pragma pack(1)
template <class T>
class Stacknode
{
    public:
        T data;
        Stacknode<T> * next;

        Stacknode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template <class T>
class Stack
{
    private:
        Stacknode<T> * first;
        int iCount;

    public:
        Stack();

        void push(T);             
        T pop();                  
        T peep();

        void Display();
        int Count();
};

template <class T>
Stack<T>:: Stack()
{
    cout<<"Stack gets created successfuly\n";
    this->first = NULL;
    this->iCount = 0;
}

template <class T>
void Stack<T>:: push(T no)               
{

    Stacknode<T> * newn = NULL;
    newn = new Stacknode<T>(no);

    newn->next = this->first;
    this->first = newn;

    this->iCount++;
}

template <class T>
T Stack<T>:: pop()                 
{
    T Value = 0;
    Stacknode<T> * temp = this->first;

    if(this->first == NULL)
    {
        cout<<"Stack is empty\n";
        return -1;
    }

    Value = this->first->data;

    this->first = this->first->next;
    delete temp;

    this->iCount--;

    return Value;

}

template <class T>
T Stack<T> :: peep()
{
    T Value = 0;

    if(this->first == NULL)
    {
        cout<<"Stack is empty\n";
        return -1;
    }

    Value = this->first->data;
    
    return Value;
}

template <class T>
void Stack<T> :: Display()
{
    Stacknode<T> * temp = this->first;

    if(this->first == NULL)
    {
        cout<<"Stack is empty\n";
        return;
    }

    while(temp != NULL)
    {
        cout<<"|\t"<<temp->data<<"\t|\n";
        temp = temp->next;
    }
    cout<<"\n";
}

template <class T>
int Stack<T>:: Count()
{
    return this->iCount;
}



int main()
{
    Stack<char> *stobj = new Stack<char>();

    stobj->push('A');
    stobj->push('B');
    stobj->push('C');
    stobj->push('D');

    stobj->Display();
    cout<<"Number of elements in Stack are: "<<stobj->Count()<<"\n\n";

    cout<<"Return value of peep is: "<<stobj->peep()<<"\n";

    stobj->Display();
    cout<<"Number of elements in Stack are: "<<stobj->Count()<<"\n\n";

    cout<<"Poped element is: "<<stobj->pop()<<"\n";

    stobj->Display();
    cout<<"Number of elements in Stack are: "<<stobj->Count()<<"\n\n";

    cout<<"Poped element is: "<<stobj->pop()<<"\n";

    stobj->Display();
    cout<<"Number of elements in Stack are: "<<stobj->Count()<<"\n\n";
    
    stobj->push('E');

    stobj->Display();
    cout<<"Number of elements in Stack are: "<<stobj->Count()<<"\n\n";

    delete stobj;
    return 0;
}