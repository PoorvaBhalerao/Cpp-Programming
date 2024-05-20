#include<iostream>
using namespace std;

class Base
{
    public:
        int A;
    private:
        int B;
    protected:
        int C;
    public:
        Base()
        {
            A = 10; B = 20; C = 30;
        }
        void Fun()
        {
            cout<<A<<"\n";  //Allowed
            cout<<B<<"\n";  //Allowed
            cout<<C<<"\n";  //Allowed
        }
};

class Derived:public Base
{
    public:
        void Gun()
        {
            cout<<A<<"\n";  //Allowed
            cout<<B<<"\n";  //Not Allowed...private memnbers can only be accessible to Parent class only
            cout<<C<<"\n";  //Allowed
        }
};

int main()
{
    Base bobj;

    cout<<bobj.A<<"\n"; //Allowed
    cout<<bobj.B<<"\n"; //Not Allowed...private members can only be accessible to Parent class only
    cout<<bobj.C<<"\n"; //Not Allowed...protected members can be accessible to parent and his child/derived class
    
    return 0;
}