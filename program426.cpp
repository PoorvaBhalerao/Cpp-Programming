// Singly Linear Linked List
//InsertFirst(written in new way / updated), InsertLast, Display, Count

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
            first = NULL;
            iCount = 0;
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

            iCount++;
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
            iCount++;
        }

        void DeleteFirst()
        {

        }

        void DeleteLast()
        {}
        
        void InsertAtPos(int no, int pos)
        {}

        void DeleteAtPos(int pos)
        {}

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
    
    return 0;
}
