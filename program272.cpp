// Accept N numbers from user and display addition of N numbers (generic programming).

#include<iostream>
using namespace std;

template <class T>
T Summation(T Arr[], int iSize)
{
    int iCnt = 0;
    T fSum;                         

    for(iCnt = 1, fSum = Arr[0]; iCnt< iSize; iCnt++)   // change.... if garbage is there in iSum because of uninitialisation 
                                                        // then from this step garbage is removed
    {
        fSum = fSum + Arr[iCnt];
    }

    return fSum;
}

int main()
{
    float Brr[] = {10.1f,20.2f,30.3f,40.4f,50.5f};
    float fRet = 0.0f;

    fRet = Summation(Brr, 5);

    cout<<"Summation is: "<<fRet<<"\n";    

    return 0;
}