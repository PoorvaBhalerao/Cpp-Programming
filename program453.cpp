//Doubly Linear Linked List... Final Code
//InsertFirst, InsertLast, Display, Count, DeleteFirst, DeleteLast, InsertAtPos, DeleteAtPos

#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node* PNODE;

class DoublyLL
{
    private:
        PNODE first;
        int iCount;

    public:
        DoublyLL();

        void InsertFirst(int no);

        void InsertLast(int no);

        void DeleteFirst();

        void DeleteLast();

        void Display();

        int Count();

        void InsertAtPos(int no, int pos);

        void DeleteAtPos(int pos);
};

DoublyLL::DoublyLL()
{
    cout<<"Object of DoublyLL is created\n";
    this->first = NULL;
    this->iCount = 0;
}

void DoublyLL :: InsertFirst(int no)
{
    PNODE newn = NULL;
    newn = new NODE;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

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

void DoublyLL ::InsertLast(int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = new NODE;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

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

void DoublyLL ::DeleteFirst()
{
    
    if(this->first == NULL)
    {
        cout<<"LL is empty\n";
        return;
    }
    else if(this->first->next == NULL)
    {
        delete this->first;
        this->first->next = NULL;
        this->first->prev = NULL;
    }
    else
    {
        this->first = this->first->next;
        delete(this->first->prev);
        this->first->prev = NULL;
    }
    this->iCount--;
}

void DoublyLL ::DeleteLast()
{
    PNODE temp = NULL;
    if(this->first == NULL)
    {
        cout<<"LL is empty\n";
        return;
    }
    else if(this->first->next == NULL)
    {
        delete first;
        this->first->next = NULL;
        this->first->prev = NULL;
    }
    else
    {
        temp = this->first;
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete (temp->next);
        temp->next = NULL;
    }
    this->iCount--;
}

void DoublyLL ::Display()
{
    PNODE temp = NULL;
    temp = this->first;

    cout<<"NULL <=> ";

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | <=> ";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

int DoublyLL ::Count()
{
    return this->iCount;
}

void DoublyLL ::InsertAtPos(int no, int pos)
{
    PNODE temp = NULL;
    PNODE newn = NULL;
    int iCnt = 0;

    if((pos < 1) || (pos > (this->iCount+1)))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new NODE;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = this->first;
        
        for(iCnt = 1; iCnt <pos-1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;

        this->iCount++;
    }
}

void DoublyLL ::DeleteAtPos(int pos)
{
    PNODE temp = NULL;
    
    int iCnt = 0;

    if((pos < 1) || (pos > (this->iCount)))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;
        
        for(iCnt = 1; iCnt <pos-1; iCnt++)
        {
            temp = temp->next;
        }
        
        temp->next = temp->next->next;
        temp->next->prev = temp;

        this->iCount--;
    }
}

int main()
{
    DoublyLL obj;
    int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are: "<<iRet<<"\n";

    obj.InsertLast(101);
    obj.InsertLast(121);
    obj.InsertLast(151);

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are: "<<iRet<<"\n";

    obj.DeleteFirst();

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are: "<<iRet<<"\n";

    obj.DeleteLast();

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are: "<<iRet<<"\n";

    obj.InsertAtPos(555, 4);

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are: "<<iRet<<"\n";

    obj.DeleteAtPos(4);

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are: "<<iRet<<"\n";

    return 0;
}