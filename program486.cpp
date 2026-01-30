////////////////////////////////////////////////////////////////////
// Final code of  Singly Linear Linked List using Generic approach
////////////////////////////////////////////////////////////////////
 
#include<iostream>
using namespace std;

#pragma pack(1)
template <class T>
class SinglyLLLnode
{
    public: 
        T data;
        SinglyLLLnode<T> * next;

        SinglyLLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template <class T>
class SinglyLLL
{
    private:                // IMPORTANT
        SinglyLLLnode<T> * first;
        int iCount;
    
    public:
        SinglyLLL();        

        void InsertFirst(T);        
        void InsertLast(T);       
        void InsertAtPos(T, int);     
        
        void DeleteFirst();        
        void DeleteLast();        
        void DeleteAtPos(int);       

        void Display();
        int Count();

};

template <class T>
SinglyLLL<T>::SinglyLLL()
{
    cout<<"Object os SinglyLL gets created"<<"\n";
    this->first = NULL;
    this->iCount = 0;
}

template <class T>
void SinglyLLL<T>::InsertFirst(T no)
{
    SinglyLLLnode<T> *newn = NULL;
    
    newn = new SinglyLLLnode<T>(no);
    
    newn->data = no;
    newn->next = NULL;

    newn->next = this->first;              
    this->first = newn;

    this->iCount++;
}

template <class T>
void SinglyLLL<T>::InsertLast(T no)
{
    SinglyLLLnode<T> * newn = NULL;
    SinglyLLLnode<T> * temp = NULL;
    
    newn = new SinglyLLLnode<T>(no);
    
    newn->data = no;
    newn->next = NULL;

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
    }
    this->iCount++;
}

template <class T>
void SinglyLLL<T>::DeleteFirst()
{
    SinglyLLLnode<T> * temp = NULL;
    if(this->first == NULL)                       
    {
        cout<<"LL is empty\n";
        return;
    }
    else if(this->first->next == NULL)           
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;
        this->first = this->first->next;
        delete temp;
    }
    this->iCount--;
}

template <class T>
void SinglyLLL<T>::DeleteLast()
{
    SinglyLLLnode<T> * temp = NULL;
    if(this->first == NULL)                       
    {
        cout<<"LL is empty\n";
        return;
    }
    else if(this->first->next == NULL)            
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete(temp->next);
        temp->next = NULL;
    }
    this->iCount--;
}

template <class T>
void SinglyLLL<T>::InsertAtPos(T no, int pos)
{
    int iCnt = 0;
    SinglyLLLnode<T> * temp = NULL;
    SinglyLLLnode<T> * newn = NULL;

    if((pos == 1) || (pos == (this->iCount+1)))             
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == (this->iCount+1))
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new SinglyLLLnode<T>(no);
        newn->data = no;
        newn->next = NULL;

        temp = this->first;

        for(iCnt = 1; iCnt <pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        this->iCount++;                
    }
}

template <class T>
void SinglyLLL<T>::DeleteAtPos(int pos)
{
    int iCnt = 0;
    SinglyLLLnode<T> * temp = NULL;
    SinglyLLLnode<T> * target = NULL;

    if((pos == 1) || (pos == this->iCount))             
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
        target = temp->next;

        temp->next = temp->next->next;
        delete target;

        this->iCount--;    
    }
}

template <class T>
void SinglyLLL<T>:: Display()
{
    SinglyLLLnode<T> * temp = NULL;
    temp = this->first;
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp->next;
    }
    cout<<"NULL\n";
} 

template <class T>
int SinglyLLL<T>::Count()
{
    return this->iCount;
}


int main()
{
    SinglyLLL<int> *sobj = new SinglyLLL<int>();
    int iRet = 0;

    sobj->InsertFirst(51);
    sobj->InsertFirst(21);
    sobj->InsertFirst(11);

    sobj->Display();
    iRet = sobj->Count();
    cout<<"Number of nodes are: "<<iRet<<"\n";

    sobj->InsertLast(101);
    sobj->InsertLast(111);
    sobj->InsertLast(121);

    sobj->Display();
    iRet = sobj->Count();
    cout<<"Number of nodes are: "<<iRet<<"\n";

    sobj->DeleteFirst();

    sobj->Display();
    iRet = sobj->Count();
    cout<<"Number of nodes are: "<<iRet<<"\n";

    sobj->DeleteLast();

    sobj->Display();
    iRet = sobj->Count();
    cout<<"Number of nodes are: "<<iRet<<"\n";

    sobj->InsertAtPos(555,4);

    sobj->Display();
    iRet = sobj->Count();
    cout<<"Number of nodes are: "<<iRet<<"\n";

    sobj->DeleteAtPos(4);

    sobj->Display();
    iRet = sobj->Count();
    cout<<"Number of nodes are: "<<iRet<<"\n";

    delete sobj;
    
    return 0;
}
