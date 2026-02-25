//Sorting Algorithms
//Bubble Sort

#include<iostream>
using namespace std;

class ArrayX
{
    public:
        int *Arr;    
        int iSize;
        bool Sorted;

        ArrayX(int);
        ~ArrayX();
        
        void Accept();
        void Display();
        
        bool CheckSorted();

        void BubbleSort();
};


ArrayX :: ArrayX(int no)
{
    cout<<"Inside constructor"<<"\n";
    iSize = no;
    Arr = new int[iSize];
    Sorted = true;
}

ArrayX :: ~ArrayX()
{
    cout<<"Inside Destructor"<<"\n";
    delete [] Arr;
}

void ArrayX :: Accept()
{
    int iCnt = 0;
    cout << "Enter the elements: "<<"\n";

    cin >> Arr[iCnt];

    for(iCnt = 1; iCnt <iSize; iCnt++)
    {
        cin >> Arr[iCnt];

        if(Arr[iCnt-1] > Arr[iCnt])
        {
            this->Sorted = false;
        }
    }

    //this->Sorted = CheckSorted();
}

void ArrayX ::  Display()
{
    int iCnt = 0;
    cout << "Elements of the array are : "<<"\n";

    for(iCnt = 0; iCnt <iSize; iCnt++)
    {
        cout << Arr[iCnt] <<"\t";
    }
    cout<<"\n";
}


bool ArrayX :: CheckSorted()
{
    bool bFlag = true;
    int i = 0;

    for(i = 0; i < this->iSize-1 ; i++)
    {
        if(Arr[i] > Arr[i+1])
        {
            bFlag = false;
            break;
        }        
    }

    return bFlag;
}


void ArrayX :: BubbleSort()
{
    int i = 0, j = 0;
    int temp = 0;

    for(i = 0; i< this->iSize-1; i++)                   // Outer Loop
    {
        for(j = 0; j < this->iSize-1-i ; j++)           // Inner Loop
        {
            if(Arr[j] > Arr[ j + 1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
            }
        }
    }

    this->Sorted = true;
}



int main()
{
    int iValue = 0;

    cout<<"Enter the number of elements :"<<"\n";
    cin>>iValue;

    ArrayX aobj(iValue);                            //static memory allocation
    
    aobj.Accept();

    cout<<"Data Before Sorting\n";
    aobj.Display();

    aobj.BubbleSort();

    cout<<"Data After Sorting\n";
    aobj.Display();
    
    

    return 0;
}