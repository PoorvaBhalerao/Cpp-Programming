// Singly Linear Linked List                // Final Code
//InsertFirst, InsertLast, Display, Count, DeleteFirst, DeleteLast, InsertAtPos, DeleteAtPos

#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node* PPNODE;

class SinglyLL
{
    public:
        PNODE first;
        int iCount;
    
        SinglyLL()
        {
            cout<<"Object os SinglyLL gets created"<<"\n";
            this->first = NULL;
            this->iCount = 0;
        }

        void InsertFirst(int no)
        {
            PNODE newn = NULL;
            
            newn = new NODE;
            
            newn->data = no;
            newn->next = NULL;

            // if(first == NULL)
            // {
            //     first = newn;
            // }
            // else
            // {
            //     newn->next = first;
            //     first = newn;
            // }

            newn->next = first;              // Instead of writing above two conditions we can write like this
            first = newn;

            this->iCount++;
        }

        void InsertLast(int no)
        {
            PNODE newn = NULL;
            PNODE temp = NULL;
            
            newn = new NODE;
            
            newn->data = no;
            newn->next = NULL;

            if(first == NULL)                   // OR if(iCount == 0)
            {
                first = newn;
            }
            else
            {
                temp = first;
                while(temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = newn;
            }
            this->iCount++;
        }

        void DeleteFirst()
        {
            PNODE temp = NULL;
            if(first == NULL)                       // OR if(iCount == 0)
            {
                cout<<"LL is empty\n";
                return;
            }
            else if(first->next == NULL)            // OR if(iCount == 1)
            {
                delete first;
                first = NULL;
            }
            else
            {
                temp = first;
                first = first->next;
                delete temp;
            }
            this->iCount--;
        }

        void DeleteLast()
        {
            PNODE temp = NULL;
            if(first == NULL)                       // OR if(iCount == 0)
            {
                cout<<"LL is empty\n";
                return;
            }
            else if(first->next == NULL)            // OR if(iCount == 1)
            {
                delete first;
                first = NULL;
            }
            else
            {
                temp = first;
                while(temp->next->next != NULL)
                {
                    temp = temp->next;
                }
                delete(temp->next);
                temp->next = NULL;
            }
            this->iCount--;
        }
        
        void InsertAtPos(int no, int pos)
        {
            int iCnt = 0;
            PNODE temp = NULL;
            PNODE newn = NULL;

            if((pos == 1) || (pos == (this->iCount+1)))             // instead of iSize variable directly iCount is used
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
                newn = new NODE;
                newn->data = no;
                newn->next = NULL;

                temp = first;

                for(iCnt = 1; iCnt <pos-1; iCnt++)
                {
                    temp = temp->next;
                }

                newn->next = temp->next;
                temp->next = newn;

                this->iCount++;                
            }
        }

        void DeleteAtPos(int pos)
        {
            int iCnt = 0;
            PNODE temp = NULL;
            PNODE target = NULL;

            if((pos == 1) || (pos == this->iCount))             // instead of iSize variable directly iCount is used
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
                temp = first;

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

        void Display()
        {
            PNODE temp = NULL;
            temp = first;
            while(temp != NULL)
            {
                cout<<"| "<<temp->data<<" | -> ";
                temp = temp->next;
            }
            cout<<"NULL\n";
        } 
        
        int Count()
        {
            return iCount;
        }

};

int main()
{
    SinglyLL obj;
    int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are: "<<iRet<<"\n";

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);

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

    obj.InsertAtPos(555,4);

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are: "<<iRet<<"\n";

    obj.DeleteAtPos(4);

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are: "<<iRet<<"\n";
    
    return 0;
}
