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
class Derivedx : public Derived     //grandchild
{
    public:
        int P;
        Derivedx()
        {
            cout<<"Inside Derivedx constructor\n";
            P = 111;
        }
        ~Derivedx()
        {
            cout<<"Inside Derivedx destructor\n";
        }
        void Sun()
        {
            cout<<"Inside Derivedx Sun\n";
        }
};

int main()
{   
    Derivedx dobj;   //Base constructor      
                    //Derived constructor   //Derivedx constructor
    cout<<"Size of object is: "<<sizeof(dobj)<<"\n";        //20

    cout<<dobj.A<<"\n"; //11
    cout<<dobj.B<<"\n"; //21    
    cout<<dobj.X<<"\n"; //51
    cout<<dobj.Y<<"\n"; //101
    cout<<dobj.P<<"\n";//111

    dobj.Fun(); //Base Fun
    dobj.Gun(); //Derived Gun
    dobj.Sun(); //Derivedx Sun

    //Derivedx destructor
    //Derived destrucor
    //Base destructor
    return 0;
}