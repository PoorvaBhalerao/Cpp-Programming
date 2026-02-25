//Searching and Sorting Algorithms
// Linear, Bidirectional, Binary Search(incomplete code)

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
        bool LinearSearch(int);
        bool BiDirectionalSearch(int);
        bool CheckSorted();
        bool BinarySearch(int);
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
            Sorted = false;
        }
    }

    //Sorted = CheckSorted();
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

bool ArrayX :: LinearSearch(int no)
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

bool ArrayX :: BiDirectionalSearch(int no)
{
    bool bFlag = false;
    int iStart = 0;
    int iEnd = 0;

    for(iStart = 0, iEnd = iSize-1 ; iStart <= iEnd ; iStart++, iEnd--)
    {
        if((Arr[iStart] == no) || (Arr[iEnd] == no))
        {
            bFlag = true;
            break;
        }
    }
    
    return bFlag;
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

bool ArrayX :: BinarySearch(int iNo)
{
    int iStart = 0, iEnd = 0, iMid = 0;
    bool bFlag = false;

    if(this->Sorted == false)
    {
        return false;
    }

    iStart = 0;
    iEnd = iSize-1;
    
    while(iStart <= iEnd)
    {
        iMid = (iStart) + ((iEnd - iStart)/2);

        if(Arr[iMid] == iNo)
        {
            bFlag = true;
            break;
        }
        else if(iNo < Arr[iMid])
        {
            iEnd = iMid-1;
        }
        else if(iNo > Arr[iMid])
        {
            iStart = iMid+1;
        }

    }

    return bFlag;
}




int main()
{
    int iValue = 0;

    cout<<"Enter the number of elements :"<<"\n";
    cin>>iValue;

    ArrayX aobj(iValue);                            //static memory allocation
    
    aobj.Accept();
    aobj.Display();
    
    // if(aobj.LinearSearch(21))
    // {
    //     cout<<"Element is Present\n";
    // }
    // else
    // {
    //     cout<<"There is no such Element\n";
    // }

    // if(aobj.BiDirectionalSearch(21))
    // {
    //     cout<<"Element is Present\n";
    // }
    // else
    // {
    //     cout<<"There is no such Element\n";
    // }

    // if(aobj.CheckSorted())
    // {
    //     cout<<"Data is Sorted\n";
    // }
    // else
    // {
    //     cout<<"Data is not sorted\n";
    // }

    // if(aobj.Sorted == true)
    // {
    //     cout<<"Data is Sorted\n";
    // }
    // else
    // {
    //     cout<<"Data is not sorted\n";
    // }

    if(aobj.BinarySearch(25) == true)
    {
        cout<<"Element is present\n";
    }
    else
    {
        cout<<"There is no such element\n";
    }

    return 0;
}