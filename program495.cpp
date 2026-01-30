///////////////////////////////////////////////////////////////////////
//          Generalised Data Structure Library with main ----2
//////////////////////////////////////////////////////////////////////

/*
-------------------------------------------------------------------------------------------------
Type                    Name of class for node              Name of class for Functionality
-------------------------------------------------------------------------------------------------  
Singly Linear           SinglyLLLnode                       SinglyLLL
Singly Circular         SinglyCLLnode                       SinglyCLL
Doubly Linear           DoublyLLLnode                       DoublyLLL
Doubly Circular         DoublyCLLnode                       DoublyCLL
Stack                   Stacknode                           Stack

-------------------------------------------------------------------------------------------------
*/

#include<iostream>
using namespace std;

////////////////////////////////////////////////////////////////////
//          Singly Linear Linked List using Generic approach
////////////////////////////////////////////////////////////////////

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
    cout<<"Object os SinglyLLL gets created"<<"\n";
    this->first = NULL;
    this->iCount = 0;
}

///////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name   :   InsertFirst   
//      Input           :   Data of node
//      Output          :   Nothing
//      Description     :   Used to Insert node at First Position
//      Author          :   Poorva Rohan Bhalerao
//      Date            :   06/01/2026
//
//////////////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////
//        Doubly Linear Linked List using Generic approach
////////////////////////////////////////////////////////////////////

#pragma pack(1)
template <class T>
class DoublyLLLnode
{
    public:
        T data;
        DoublyLLLnode *next;
        DoublyLLLnode *prev;

        DoublyLLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
            this->prev = NULL;
        }
};

template <class T>
class DoublyLLL
{
    private:
        DoublyLLLnode<T> * first;
        int iCount;

    public:
        DoublyLLL();
        
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
DoublyLLL<T> :: DoublyLLL()
{
    cout<<"Object of DoublyLLL gets created\n";
    this->first = NULL;
    this->iCount = 0;
}

template <class T>
void DoublyLLL<T> :: InsertFirst(T no)
{
    DoublyLLLnode<T> *newn = NULL;
    newn = new DoublyLLLnode<T>(no);            
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

template <class T>
void DoublyLLL<T> :: InsertLast(T no)
{
    DoublyLLLnode<T> *newn = NULL;
    DoublyLLLnode<T> *temp = NULL;
    
    newn = new DoublyLLLnode<T>(no);            

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

template <class T>
void DoublyLLL<T> :: InsertAtPos(T no, int pos)
{
    int iCnt = 0;
    DoublyLLLnode<T> *temp = NULL;
    DoublyLLLnode<T> *newn = NULL;

    if((pos < 1) || (pos > this->iCount+1))
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
        newn = new DoublyLLLnode<T>(no);
        temp = this->first;

        for(iCnt = 1; iCnt< pos-1 ;iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        newn->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;     
        
        this->iCount++;
    }
}

template <class T>
void DoublyLLL<T> :: DeleteFirst()
{
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
        this->first = this->first->next;
        delete this->first->prev;
        this->first->prev = NULL;
    }
    this->iCount--;
}

template <class T>
void DoublyLLL <T>:: DeleteLast()
{
    DoublyLLLnode<T> *temp = NULL;

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
        delete temp->next;
        temp->next = NULL;

    }
    this->iCount--;
}

template <class T>
void DoublyLLL<T> :: DeleteAtPos(int pos)
{
    int iCnt = 0;
    DoublyLLLnode<T> *temp = NULL;

    if((pos < 1) || (pos > this->iCount))
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
        delete (temp->next->prev);
        temp->next->prev = temp;

        this->iCount--;
    }
}

template <class T>
void DoublyLLL<T> :: Display()
{
    DoublyLLLnode<T> *temp = NULL;
    temp = this->first;

    cout<<"NULL <=>";
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |<=>";
        temp = temp->next;
    }
    cout<<" NULL\n";
}

template <class T>
int DoublyLLL<T> :: Count()
{
    return this->iCount;
}

////////////////////////////////////////////////////////////////////
//        Singly Circular Linked List using Generic approach
////////////////////////////////////////////////////////////////////

template <class T>
class SinglyCLLnode
{
    public:
        T data;
        SinglyCLLnode * next;

        SinglyCLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template <class T>
class SinglyCLL
{
    private:
        SinglyCLLnode<T> * first;
        SinglyCLLnode<T> * last;
        int iCount;

    public:
        SinglyCLL();
        void InsertFirst(T);
        void InsertLast(T);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void DeleteAtPos(int);
        void InsertAtPos(T, int);
};

template <class T>
SinglyCLL<T>::SinglyCLL()
{
    cout<<"Inside constructor of SinglyCLL\n";

    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

template <class T>
void SinglyCLL<T>::InsertFirst(T no)
{
    SinglyCLLnode<T> * newn = NULL;

    newn = new SinglyCLLnode<T>(no);

    if(this->first == NULL && this->last == NULL)   
    {
        this->first = newn;
        this->last = newn;

        this->last->next = this->first;
    }
    else
    {
        newn->next = this->first;
        this->first = newn;

        this->last->next = this->first;
    }

    this->iCount++;
}

template <class T>
void SinglyCLL<T>::InsertLast(T no)
{
    SinglyCLLnode<T> * newn = NULL;

    newn = new SinglyCLLnode<T>(no);

    if(this->first == NULL && this->last == NULL)   
    {
        this->first = newn;
        this->last = newn;

        this->last->next = this->first;
    }
    else
    {
        this->last->next = newn;
        this->last = newn;

        this->last->next = this->first;
    }

    this->iCount++;
}

template <class T>
void SinglyCLL<T>::InsertAtPos(T no, int pos)
{
    SinglyCLLnode<T> * temp = NULL;
    SinglyCLLnode<T> * newn = NULL;

    int i = 0;

    if(pos < 1 || pos > this->iCount+1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new SinglyCLLnode<T>(no);

        temp = this->first;

        for(i = 1; i < pos -1; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp -> next;
        temp->next = newn;

        this->iCount++;
    }
}

template <class T>
void SinglyCLL<T>::DeleteFirst()
{
    if(this->first == NULL && this->last == NULL)
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;

        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        this->first = this->first -> next;
        delete this->last->next;

        this->last->next = this->first;
    }
    this->iCount--;
}

template <class T>
void SinglyCLL<T>::DeleteLast()
{
    SinglyCLLnode<T> * temp = NULL;

    if(this->first == NULL && this->last == NULL)
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;

        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        temp = this->first;

        while(temp -> next != this->last)
        {
            temp = temp -> next;
        }

        delete this->last;
        this->last = temp;

        this->last->next = this->first;
    }
    this->iCount--;
}

template <class T>
void SinglyCLL<T>::DeleteAtPos(int pos)
{
    SinglyCLLnode<T> * temp = NULL;
    SinglyCLLnode<T> * target = NULL;
    
    int i = 0;
    
    if(pos < 1 || pos > this->iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for(i = 1; i < pos-1; i++)
        {
            temp = temp -> next;
        }

        target = temp -> next;

        temp->next = target->next;
        delete target;

        this->iCount--;
    }
}

template <class T>
void SinglyCLL<T>::Display()
{
    if(this->first == NULL && this->last == NULL)
    {
        return;
    }

    SinglyCLLnode<T> * temp = this->first;

    cout<<"-> ";
    do
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp -> next;
    } while (temp != this->last ->next);
    
    cout<<"\n";
}

template <class T>
int SinglyCLL<T>::Count()
{
    return this->iCount;
}


////////////////////////////////////////////////////////////////////
//        Doubly Circular Linked List using Generic approach
////////////////////////////////////////////////////////////////////

template <class T>
class DoublyCLLnode
{
    public:
        T data;
        DoublyCLLnode<T> *next;
        DoublyCLLnode<T> *prev;

        DoublyCLLnode(T no)
        {
            data = no;
            next = NULL;
            prev = NULL;
        }
};

template <class T>
class DoublyCLL
{
    private:
        DoublyCLLnode<T> * first;
        DoublyCLLnode<T> * last;
        int iCount;
    
    public:
        DoublyCLL();

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
DoublyCLL<T>::DoublyCLL()
{
    cout<<"Object of DoublyCLL gets created"<<"\n";
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

template <class T>
void DoublyCLL<T>::InsertFirst(T no)
{
    DoublyCLLnode<T> * newn = NULL;
    newn = new DoublyCLLnode<T>(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        newn->next = this->first;
        this->first->prev = newn;
        this->first = newn;
    }
    this->last->next = this->first;
    this->first->prev = this->last;

    this->iCount++;
}

template <class T>
void DoublyCLL<T>::InsertLast(T no)
{
    DoublyCLLnode<T> * newn = NULL;
    newn = new struct DoublyCLLnode<T>(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn;
        newn->prev = this->last;
        this->last = newn;
    }
    this->last->next = this->first;
    this->first->prev = this->last;

    this->iCount++;
}

template <class T>  
void DoublyCLL<T>::InsertAtPos(T no, int pos)
{
    DoublyCLLnode<T> * temp = NULL;
    DoublyCLLnode<T> * newn = NULL;
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
        newn = new struct DoublyCLLnode<T>(no);
        temp = this->first;
        
        for(iCnt = 1; iCnt <pos-1; iCnt++)
        {
            temp = temp->next;
        }
        
        newn->next = temp->next;
        newn->next->prev = newn;
        newn->prev = temp;
        temp->next = newn;

        this->iCount++;
    }
}

template <class T>
void DoublyCLL<T>::DeleteFirst()
{
    if(this->first == NULL && this->last == NULL)
    {
        cout<<"LL is empty\n";
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        this->first = this->first->next;
        delete this->first->prev;
    }

    this->last->next = this->first;
    this->first->prev = this->last;

    this->iCount--;

}

template <class T>
void DoublyCLL<T>::DeleteLast()
{
    if(this->first == NULL && this->last == NULL)
    {
        cout<<"LL is empty\n";
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        this->last = this->last->prev;
        delete this->last->next;
    }

    this->last->next = this->first;
    this->first->prev = this->last;

    this->iCount--;

}

template <class T>
void DoublyCLL<T>::DeleteAtPos(int pos)
{
    DoublyCLLnode<T> * temp = NULL;
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
        delete temp->next->prev;
        temp->next->prev = temp;

        this->iCount--;
    }
}

template <class T>
void DoublyCLL<T>::Display()
{
    DoublyCLLnode<T> * temp = NULL;
    temp = this->first;

    if(this->first == NULL && this->last == NULL)
    {
        cout<<"LL is empty\n";
        return;
    }

    cout<<" <=> ";
    do 
    {
        cout<<"| "<<temp->data<<" | <=> ";
        temp = temp->next;
    }while(temp != this->last->next);

    cout<<"\n";
} 

template <class T>
int DoublyCLL<T>::Count()
{
    return this->iCount;
}

////////////////////////////////////////////////////////////////////
//          Stack using Generic approach
////////////////////////////////////////////////////////////////////

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




/////////////////////////////////////////End of Library////////////////////////////////////////////////////////

int main()
{
    SinglyLLL<int> *sobj = new SinglyLLL<int>();

    int iRet = 0;

    sobj->InsertFirst(51);
    sobj->InsertFirst(21);
    sobj->InsertFirst(11);

    sobj->Display();
    iRet = sobj->Count();
    cout<<"Number of nodes are: "<<iRet<<"\n\n";

    sobj->InsertLast(101);
    sobj->InsertLast(111);
    sobj->InsertLast(121);

    sobj->Display();
    iRet = sobj->Count();
    cout<<"Number of nodes are: "<<iRet<<"\n\n";

    sobj->DeleteFirst();

    sobj->Display();
    iRet = sobj->Count();
    cout<<"Number of nodes are: "<<iRet<<"\n\n";

    sobj->DeleteLast();

    sobj->Display();
    iRet = sobj->Count();
    cout<<"Number of nodes are: "<<iRet<<"\n\n";

    sobj->InsertAtPos(555,4);

    sobj->Display();
    iRet = sobj->Count();
    cout<<"Number of nodes are: "<<iRet<<"\n\n";

    sobj->DeleteAtPos(4);

    sobj->Display();
    iRet = sobj->Count();
    cout<<"Number of nodes are: "<<iRet<<"\n";

    cout<<"\n\n";
    /////////////////////////////////////////////////////////////////////////////
    DoublyLLL<int> *dobj = new DoublyLLL<int>();

    dobj->InsertFirst('c');
    dobj->InsertFirst('b');
    dobj->InsertFirst('a');

    dobj->Display();
    cout<<"Number of elements are: "<<dobj->Count()<<"\n\n";

    dobj->InsertLast('X');
    dobj->InsertLast('Y');
    dobj->InsertLast('Z');

    dobj->Display();
    cout<<"Number of elements are: "<<dobj->Count()<<"\n\n";

    dobj->DeleteFirst();

    dobj->Display();
    cout<<"Number of elements are: "<<dobj->Count()<<"\n\n";

    dobj->DeleteLast();

    dobj->Display();
    cout<<"Number of elements are: "<<dobj->Count()<<"\n\n";

    dobj->InsertAtPos('#', 4);

    dobj->Display();
    cout<<"Number of elements are: "<<dobj->Count()<<"\n\n";

    dobj->DeleteAtPos(4);

    dobj->Display();
    cout<<"Number of elements are: "<<dobj->Count()<<"\n\n";

    cout<<"\n\n";
    //////////////////////////////////////////////////////////////////////////////
    SinglyCLL<int> *scobj = new SinglyCLL<int>();

    scobj->InsertFirst(51);
    scobj->InsertFirst(21);
    scobj->InsertFirst(11);

    scobj->Display();
    cout<<"Number of elements are : "<<scobj->Count()<<"\n\n";
    
    scobj->InsertLast(101);
    scobj->InsertLast(111);
    scobj->InsertLast(121);

    scobj->Display();
    cout<<"Number of elements are : "<<scobj->Count()<<"\n\n";
    
    scobj->DeleteFirst();

    scobj->Display();
    cout<<"Number of elements are : "<<scobj->Count()<<"\n\n";
    
    scobj->DeleteLast();

    scobj->Display();
    cout<<"Number of elements are : "<<scobj->Count()<<"\n\n";
    
    scobj->InsertAtPos(105,5);

    scobj->Display();
    cout<<"Number of elements are : "<<scobj->Count()<<"\n";
    
    scobj->DeleteAtPos(5);

    scobj->Display();
    cout<<"Number of elements are : "<<scobj->Count()<<"\n\n";

    cout<<"\n\n";
    ////////////////////////////////////////////////////////////////////////////////////////
    DoublyCLL<int> *dcobj = new DoublyCLL<int>();

    dcobj->InsertFirst(51);
    dcobj->InsertFirst(21);
    dcobj->InsertFirst(11);

    dcobj->Display();
    cout<<"Number of nodes are: "<<dcobj->Count()<<"\n\n";

    dcobj->InsertLast(101);
    dcobj->InsertLast(111);
    dcobj->InsertLast(121);

    dcobj->Display();
    cout<<"Number of nodes are: "<<dcobj->Count()<<"\n\n";
    dcobj->DeleteFirst();

    dcobj->Display();
    cout<<"Number of nodes are: "<<dcobj->Count()<<"\n\n";

    dcobj->DeleteLast();

    dcobj->Display();
    cout<<"Number of nodes are: "<<dcobj->Count()<<"\n\n";

    dcobj->InsertAtPos(555,4);

    dcobj->Display();
    cout<<"Number of nodes are: "<<dcobj->Count()<<"\n\n";

    dcobj->DeleteAtPos(4);

    dcobj->Display();
    cout<<"Number of nodes are: "<<dcobj->Count()<<"\n\n";

    cout<<"\n\n";

//////////////////////////////////////////////////////////////////////////////////////////

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

    
    

    delete sobj;
    delete dobj;
    delete scobj;
    delete dcobj;
    delete stobj;

    return 0;
}