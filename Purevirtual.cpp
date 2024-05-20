#include<iostream>
using namespace std;

class Base
{
    public:
        int A, B;
        Base()
        {      cout<<"Base constructor\n";     }
        int Addition(int i, int j)      //1000
        {       return i+j;     }
        virtual int Substraction(int i, int j)      //2000
        {       return i-j;     }
        virtual int Multiplication(int i, int j) = 0;
};

class Derived: public Base
{
    public:
        int X, Y;
        Derived()
        {       cout<<"Derived Constructor\n";      }
        int Substraction(int i, int j)      //3000
        {       return i-j;     }
        int Multiplication(int i, int j)        //4000  
        {       return i*j;     }
        virtual int Division(int i, int j)      //5000
        {       return i/j;     }
};

int main()
{
    //Base bobj;          //Not allowed error...because it has abstract method i.e. pure virtual function
    Derived dobj;
    Base *bp = &dobj;

    cout<< bp->Addition(10,11)<<"\n";   //21...(Base Addition)
    cout<< bp->Substraction(10,11)<<"\n";   //-1...(Derived Substraction)
    cout<< bp->Multiplication(10,11)<<"\n"; //110...(Derived Multiplication)
    //cout<< bp->Division(100, 10)<<"\n"; //Error...(Division is not in Base)

    return 0;
}