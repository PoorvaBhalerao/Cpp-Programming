// Searching Sorting Algorithms
//Linear Search

#include<iostream>
using namespace std;

class ArrayX
{
    public:
        int *Arr;    
        int iSize;

        ArrayX(int no)
        {
            cout<<"Inside constructor"<<"\n";
            iSize = no;
            Arr = new int[iSize];
        }

        ~ArrayX()
        {
            cout<<"Inside Destructor"<<"\n";
            delete [] Arr;
        }

        void Accept()
        {
            int iCnt = 0;
            cout << "Enter the elements: "<<"\n";

            for(iCnt = 0; iCnt <iSize; iCnt++)
            {
                cin >> Arr[iCnt];
            }
        }

        void Display()
        {
            int iCnt = 0;
            cout << "Elements of the array are : "<<"\n";

            for(iCnt = 0; iCnt <iSize; iCnt++)
            {
                cout << Arr[iCnt] <<"\t";
            }
            cout<<"\n";
        }

        bool LinearSearch(int no)
        {
            bool bFlag = false;
            int i = 0;

            for(i = 0; i<this->iSize; i++)
            {
                if(Arr[i] == no)
                {
                    bFlag = true;
                    break;
                }
            }
            
            return bFlag;
        }
};

int main()
{
    int iValue = 0;

    cout<<"Enter the number of elements :"<<"\n";
    cin>>iValue;

    ArrayX aobj(iValue);                //static memory allocation
    
    aobj.Accept();
    aobj.Display();
    
    if(aobj.LinearSearch(21))
    {
        cout<<"Element is Present\n";
    }
    else
    {
        cout<<"There is no such Element\n";
    }

   

    return 0;
}