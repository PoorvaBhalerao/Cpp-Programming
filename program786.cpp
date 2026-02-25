//Sorting Algorithms
//Bubble Sort, Bubble Sort Efficient**, Selection Sort, Insertion Sort

#include<iostream>
using namespace std;

#define INC_ORDER 1
#define DEC_ORDER 2
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
        void BubbleSortEfficient();
        void BubbleSortEfficientX(int);

        void SelectionSort();

        void InsertionSort();

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

//  21  15  18  16  11
void ArrayX :: BubbleSort()
{
    int i = 0, j = 0;
    int temp = 0;

    if(this->Sorted == true)                            // Important Filter
    {
        return;
    }

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

        cout<<"\nData After Pass: "<< i + 1 <<"\n";

        Display();
    }

    this->Sorted = true;
}

void ArrayX :: BubbleSortEfficient()
{
    int i = 0, j = 0;
    int temp = 0;
    bool bFlag = false;

    // if(this->Sorted == true)                                                                 // Important Filter
    // {
    //     return;
    // }

    bFlag = true;
    for(i = 0; (i< this->iSize-1) && (bFlag == true); i++)                                      // Outer Loop
    {
        bFlag = false;
        for(j = 0; j < this->iSize-1-i ; j++)                                                   // Inner Loop
        {
            if(Arr[j] > Arr[ j + 1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;

                bFlag = true;
            }           
        }

        cout<<"\nData After Pass: "<< i + 1 <<"\n";

        Display();
    }
    cout<<"\nNumber of passes for Bubble sort:"<<i<<"\n";
    
    this->Sorted = true;                                                                        // this is for increasing order
}


/*
    if(iSize = 5)
    Pass 1: 0   1   2   3
    Pass 2: 0   1   2
    Pass 3: 0   1   
    Pass 4: 0
*/

//1: Increasing order, 2: decreasing order
void ArrayX :: BubbleSortEfficientX(int iOption = INC_ORDER)                             // default value is INC_ORDER means increasing if not given by user                                      
{
    int i = 0, j = 0;
    int temp = 0;
    bool bFlag = false;

    if(iOption != INC_ORDER && iOption != DEC_ORDER)
    {
        cout<<"Invalid option for sorting\n";
        cout<<"1:Increasing\t2:Decreasing\n";
        return;
    }
    
    // if(this->Sorted == true)                                                          // Important Filter
    // {
    //     return;
    // }

    bFlag = true;

    if(iOption == INC_ORDER)                                                            // Increasing
    {
        for(i = 0; (i< this->iSize-1) && (bFlag == true); i++)                          // Outer Loop
        {
            bFlag = false;

            for(j = 0; j < this->iSize-1-i ; j++)                                       // Inner Loop
            {
                if(Arr[j] > Arr[ j + 1])
                {
                    temp = Arr[j];
                    Arr[j] = Arr[j+1];
                    Arr[j+1] = temp;

                    bFlag = true;
                }    
            }
                
            cout<<"\nData After Pass: "<< i + 1 <<"\n";
            Display();
        }   // end of outer loop
    }       // end of if
    else if(iOption == DEC_ORDER)
    {
        for(i = 0; (i< this->iSize-1) && (bFlag == true); i++)                          // Outer Loop
        {
            bFlag = false;

            for(j = 0; j < this->iSize-1-i ; j++)                                       // Inner Loop
            {
                if(Arr[j] < Arr[ j + 1])
                {
                    temp = Arr[j];
                    Arr[j] = Arr[j+1];
                    Arr[j+1] = temp;

                    bFlag = true;
                }    
            }
                
            cout<<"\nData After Pass: "<< i + 1 <<"\n";
            Display();
        }     // end of outer loop
    }         // end of else if
    
    cout<<"\nNumber of passes for Bubble sort:"<<i<<"\n";
    
    this->Sorted = true;
}

/*
if(iSize = 5)
    Pass 1: 1   2   3   4
    Pass 2: 1   2   3
    Pass 3: 1   2
    Pass 4: 4
*/

void ArrayX :: SelectionSort()
{
    int i = 0, j = 0, temp = 0;
    int min_index = 0;

    for(i = 0; i<(iSize -1); i++)
    {
        min_index = i;

        for(j = i+1; j < iSize; j++)
        {
            if(Arr[j] < Arr[min_index])
            {
                min_index = j;
            }
        }

        if(i != min_index)
        {
            temp = Arr[i];
            Arr[i] = Arr[min_index];
            Arr[min_index] = temp;
        }
        
    }
}


void ArrayX :: InsertionSort()
{
    int i = 0, j = 0;
    int Selected = 0;

    for(i = 1; i<iSize; i++)
    {
        for(j = i-1, Selected = Arr[i]; (j >= 0) && (Arr[j] > Selected); j--)
        {
            Arr[j+1] = Arr[j];
        }
        Arr[j+1] = Selected;
    }

}


int main()
{
    int iValue = 0;

    cout<<"Enter the number of elements :"<<"\n";
    cin>>iValue;

    ArrayX aobj(iValue);                            //static memory allocation


    
    aobj.Accept();

    // cout<<"\nData Before Sorting\n";
    // aobj.Display();

    // aobj.BubbleSort();

    // cout<<"\nData After Sorting\n";
    // aobj.Display();
    
    // cout<<"\nData Before Sorting\n";
    // aobj.Display();

    // aobj.BubbleSortEfficient();

    // cout<<"\nData After Sorting\n";
    // aobj.Display();

    // cout<<"\nData Before Sorting\n";
    // aobj.Display();

    // //1: Increasing sort
    // //2: Decreasing sort
    // aobj.BubbleSortEfficientX(DEC_ORDER);

    // cout<<"\nData After Sorting\n";
    // aobj.Display();
    
    // cout<<"\nData Before Sorting\n";
    // aobj.Display();

    // aobj.SelectionSort();

    // cout<<"\nData After Sorting\n";
    // aobj.Display();

    cout<<"\nData Before Sorting\n";
    aobj.Display();

    aobj.InsertionSort();

    cout<<"\nData After Sorting\n";
    aobj.Display();

    return 0;
}