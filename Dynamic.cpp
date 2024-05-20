#include<iostream>
using namespace std;

int main()
{
    int *ptr = NULL
    int Size = 0;

    cout<<"Enter size of array:\n";
    cin>>Size;

    ptr = new int(Size);    //navin integer cha array dya mi sangel tya Size cha

    //ptr = (int *)malloc(Size * sizeof(int));.....syntax of malloc compare with above syntax
    //Use the memory

    //delete ptr;...if you write this then only first element is deleted
    delete []ptr;    //whole array of ptr is deleted.


    return 0;
}