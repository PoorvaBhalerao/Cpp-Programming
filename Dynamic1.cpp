#include<iostream>
using namespace std;

class Demo
{
    public:
        int A,B;
        Demo()
        {
            cout<<"Inside Contructor\n";
            A = 11;
            B = 21;
        }
        ~Demo()
        {
            cout<<"Inside Destructor\n";
        }
        void Fun()
        {
            cout<<"inside Fun function\n";
        }
};

int main()
{
    //Demo obj1;...used to create object statically

    Demo *p= new Demo;//another object created by dynamic memory allocation
    //Demo *p = (Demo *)malloc(sizeof(Demo));//...c programming..when we call by malloc constructor and deshtructor will not called.
    
    p->Fun();
    cout<<p->A<<"\n";
    cout<<p->B<<"\n";

    delete p;
    //free(p);//...c programming
    //using malloc and free we can allocate dymanic memory for object but constructor and destructor will not be called.

    return 0;
}