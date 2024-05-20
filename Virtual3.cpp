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
    Derived dobj;
    Base *bp = &dobj;       //upcasting

    bp ->Fun();
    bp ->Gun();
    bp ->Sun();
    //bp ->Run();
    return 0;
}