#include<iostream>
using namespace std;

class Demo
{
    public:
        int No1, No2;   //Non-static characteristics
        static int X;   //static characteristics//memory not get inside the object because it is static

        Demo()
        {
            this -> No1 = 10; // No1 = 10;
            this -> No2 = 20; // No2 = 20;
        }
        void Fun()  //Non static behaviour
        {
            cout<<"Inside Fun\n";
            cout<<No1<<"\n";
            cout<<X<<"\n\n";
        }
        static void Gun()   //static behaviour
        {
            cout<<"Inside Gun\n";
            cout<<X<<"\n\n";
        }

};
int Demo :: X = 11;     //if ur class contains static characteristics then they should be initialised outside class.
int main()
{
    cout<<"Value of X is: "<<Demo::X<<"\n\n"; //static characterisitcs and behaviours can be accesses before creating objects
    Demo::Gun();//because static variables not allocated inside objects it is allocated outside object

    Demo obj1;
    Demo obj2;

    cout<<"Size of object is: "<<sizeof(obj1)<<"\n\n";
    cout<<obj1.No1<<"\t"<<obj1.No2<<"\n";
    cout<<obj2.No1<<"\t"<<obj2.No2<<"\n\n";

    obj1.Fun();
    obj2.Fun();

    obj1.Gun();
    cout<<"Value of X using object is : "<<obj1.X<<"\n";

    return 0;
}