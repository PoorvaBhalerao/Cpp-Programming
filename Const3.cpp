#include<iostream>
using namespace std;

class Demo
{
    public:
        int X, Y;
        Demo()
        {
            X = 10;
            Y = 20;
        }
        void fun()      //non constant function
        {
            cout<<"Inside fun\n";
            X++;
            Y++;
        }
        void gun() const        //constant function//constant function can not change characteristics from function body
        {
            cout<<"Inside gun\n";
            //X++;    //NA
            //Y++;    //NA
        }            
};

int main()
{
    Demo obj1;
    const Demo obj2;

    obj1.fun();     //normal object normal function
    obj1.gun();     //normal object constant function

    //obj2.fun();     //comstant object normal function       //NA(Error)
    obj2.gun();     //constant object constant function

    return 0;
}