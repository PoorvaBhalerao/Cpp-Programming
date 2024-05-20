#include<iostream>
using namespace std;

class Arithmatic
{
    public:
        int No1;
        int No2;

        Arithmatic(int A, int B)
        {
            No1 = A;
            No2 = B;
        }
        int Addition()      // int Addition(Arithmatic * const this)
        {
            int Ans = 0;
            //Ans = No1 + No2;
            Ans = (this->No1) + (this->No2);
            return Ans;
        }
};

int main()
{
    int Ret = 0;
    Arithmatic obj(21, 11);

    Ret = obj.Addition();       //internally considered as Ret = Addition(&obj);  
    cout<<"Addition is: "<<Ret<<"\n";
    
    return 0;
}