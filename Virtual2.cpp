#include<iostream>
using namespace std;

class Base
{
    public:
        int A, B;
        void Fun()  //1000...imaginary addresses//Definition
        {   cout<<"Base Fun\n";   }
        void Gun()  //2000          //definition
        {   cout<<"Base Gun\n";   }
        void Sun()  //3000          //definition
        {   cout<<"Base Sun\n";   }
};

class Derived: public Base
{
    public:
        int X, Y;
        void Gun()  //4000          //redefinition
        {   cout<<"Derived Gun\n";  }
        void Sun()  //5000          //redefinition
        {   cout<<"Derived Sun\n";  }
        void Run()  //6000          //definition
        {   cout<<"Derived Run\n";  }
};

int main()
{
    Base bobj;
    Derived dobj;

    Base *bp = NULL;
    Derived *dp = NULL;

    bp = &bobj;         //nocasting
    dp = &dobj;         //nocasting

    bp = &dobj;         //upcasting
    dp = &bobj;         //downcasting(Not allowed)

    return 0;
}