#include<iostream>
//using namespace std;        //Inbuilt namespace....std is used to define cin cout

namespace Marvellous
{
    class Demo
    {
        //Logic
    };
}

namespace PPA
{
    class Hello
    {
        //Logic
    };
}

using namespace Marvellous;

int main()
{
    std::cout<<"Inside main\n";      // or if using namespace std; not written then write std::cout<<"Inside main"
    //Marvellous::Demo dobj;         // or if using namespace Marvellous; not written then write Marvellous::Demo dobj;
    Demo dobj;
    PPA::Hello hobj;


    return 0;
}