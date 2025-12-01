// OOP approach(generic program)
//Do Addition and Subtraction of numbers

#include<iostream>
using namespace std;

template <class T>
class Arithemetic
{
    public:
        T No1;
        T No2;

        Arithemetic(T A, T B)
        {
            No1 = A;
            No2 = B;
        }

        T Addition()
        {
            T Ans = 0;
            Ans = No1 + No2;
            return Ans;
        }

        T subtraction()
        {
            T Ans = 0;
            Ans = No1 - No2;
            return Ans;
        }
    
};

int main()
{
    int iRet = 0;

    Arithemetic aobj1(11, 10);      //Error
    Arithemetic aobj2(101, 50);     //Error

    iRet = aobj1.Addition();
    cout<<"Addition  of obj1 is: "<<iRet<<"\n";

    iRet = aobj1.subtraction();
    cout<<"Subtraction of obj1 is: "<<iRet<<"\n";

    iRet = aobj2.Addition();
    cout<<"Addition of obj2 is: "<<iRet<<"\n";

    iRet = aobj2.subtraction();
    cout<<"Subtraction of obj2 is: "<<iRet<<"\n";

    return 0;
}