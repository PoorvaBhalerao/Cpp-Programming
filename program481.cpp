// Doubly Linear Linked List --  
//InsertFirst, InsertLast,  Display, Count, DeleteFirst, DeleteLast

#include<iostream>
using namespace std;

#pragma pack(1)
class node
{
    public:
        int data;
        node *next;
        node *prev;

        node(int no)
        {
            this->data = no;
            this->next = NULL;
            this->prev = NULL;
        }
};


class DoublyLLL
{
    public:
        node * first;
        int iCount;

        DoublyLLL();
        
        void InsertFirst(int);
        void InsertLast(int);
        void InsertAtPos(int, int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int Count();    

};

DoublyLLL :: DoublyLLL()
{
    cout<<"LL gets created\n";
    this->first = NULL;
    this->iCount = 0;
}

void DoublyLLL :: InsertFirst(int no)
{
    node *newn = NULL;
    newn = new node(no);            // due to constructor of class node data , prev, next is automatically allocated

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        newn->next = this->first;
        this->first->prev = newn;
        this->first = newn;
    }
    this->iCount++;   

}

void DoublyLLL :: InsertLast(int no)
{
    node *newn = NULL;
    node *temp = NULL;
    
    newn = new node(no);            

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
    this->iCount++; 
}

void DoublyLLL :: InsertAtPos(int no, int pos)
{

}

void DoublyLLL :: DeleteFirst()
{
    if(this->first == NULL)                         // LL is empty
    {
        cout<<"LL is empty\n";
        return;
    }
    else if(this->first->next == NULL)              // LL contains only one node
    {
        delete this->first;
        this->first = NULL;
    }
    else                                            // LL contains more than one node
    {
        this->first = this->first->next;
        delete this->first->prev;
        this->first->prev = NULL;
    }
    iCount--;
}

void DoublyLLL :: DeleteLast()
{
    node *temp = NULL;

    if(this->first == NULL)                         // LL is empty
    {
        cout<<"LL is empty\n";
        return;
    }
    else if(this->first->next == NULL)              // LL contains only one node
    {
        delete this->first;
        this->first = NULL;
    }
    else                                            // LL contains more than one node
    {
        temp = this->first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;

    }
    iCount--;
}

void DoublyLLL :: DeleteAtPos(int pos)
{

}

void DoublyLLL :: Display()
{
    node *temp = NULL;
    temp = this->first;

    cout<<"NULL <=>";
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |<=>";
        temp = temp->next;
    }
    cout<<" NULL\n";
}

int DoublyLLL :: Count()
{
    return this->iCount;
}

int main()
{
    DoublyLLL *dobj = new DoublyLLL();

    dobj->InsertFirst(51);
    dobj->InsertFirst(21);
    dobj->InsertFirst(11);

    dobj->Display();
    cout<<"Number of elements are: "<<dobj->Count()<<"\n\n";

    dobj->InsertLast(101);
    dobj->InsertLast(111);
    dobj->InsertLast(121);

    dobj->Display();
    cout<<"Number of elements are: "<<dobj->Count()<<"\n\n";

    dobj->DeleteFirst();

    dobj->Display();
    cout<<"Number of elements are: "<<dobj->Count()<<"\n\n";

    dobj->DeleteLast();

    dobj->Display();
    cout<<"Number of elements are: "<<dobj->Count()<<"\n\n";

    delete dobj;

    return 0;
}