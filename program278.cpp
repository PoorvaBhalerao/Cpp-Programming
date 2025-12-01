// OOP approach(object oriented programming)(specific programming)
//Do Addition and Subtraction of numbers

#include<iostream>
using namespace std;

class Arithemetic
{
    public:
        int No1;
        int No2;

        Arithemetic(int A, int B)
        {
            No1 = A;
            No2 = B;
        }

        int Addition()
        {
            int Ans = 0;
            Ans = No1 + No2;
            return Ans;
        }

        int subtraction()
        {
            int Ans = 0;
            Ans = No1 - No2;
            return Ans;
        }
    
};

int main()
{
    int iRet = 0;

    Arithemetic aobj1(11, 10);
    Arithemetic aobj2(101, 50);

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