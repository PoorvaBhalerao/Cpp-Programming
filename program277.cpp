// OOP approach(object oriented programming)

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

    Arithemetic aobj(11, 10);

    iRet = aobj.Addition();
    cout<<"Addition is: "<<iRet<<"\n";

    iRet = aobj.subtraction();
    cout<<"Subtraction is: "<<iRet<<"\n";

    return 0;
}