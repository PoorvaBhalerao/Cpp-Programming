// Accept N numbers from user and display Maxmimum (generic programming).

#include<iostream>
using namespace std;

template <class T>
T Maximum(T Arr[], int iSize)
{
    int iCnt = 0;
    T iMax;                         

    iMax = Arr[0];

    for(iCnt = 0; iCnt< iSize; iCnt++)
    {
        if(Arr[iCnt] > iMax)
        {
            iMax = Arr[iCnt];
        }
    }

    return iMax;
}

int main()
{
    float Brr[] = {10.1f,20.2f,30.3f,40.4f,50.5f};
    float fRet = 0.0f;

    fRet = Maximum(Brr, 5);

    cout<<"Maximum is: "<<fRet<<"\n";    

    return 0;
}