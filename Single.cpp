#include<iostream>
using namespace std;

class Base      //parent
{
    public:
        int A, B;
        Base()
        {
            cout<<"Inside Base constructor\n";
            A = 11;
            B = 21;
        }
        ~Base()
        {
            cout<<"Inside Base destructor\n";
        }
        void Fun()
        {
            cout<<"Inside Base Fun\n";
        }
};

class Derived : public Base     //child
{
    public:
        int X, Y;
        Derived()
        {
            cout<<"Inside Derived constructor\n";
            X = 51;
            Y = 101;
        }
        ~Derived()
        {
            cout<<"Inside Derived destructor\n";
        }
        void Gun()
        {
            cout<<"Inside Derived Gun\n";
        }
};

int main()
{   
    Derived dobj;   //Base constructor      
                    //Derived constructor
    cout<<"Size of object is: "<<sizeof(dobj)<<"\n";        //16

    cout<<dobj.A<<"\n"; //11
    cout<<dobj.B<<"\n"; //21    
    cout<<dobj.X<<"\n"; //51
    cout<<dobj.Y<<"\n"; //101

    dobj.Fun(); //Base Fun
    dobj.Gun(); //Derived Gun

    //Derived destrucor
    //Base destructor
    return 0;
}