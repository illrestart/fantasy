#include <iostream>
using namespace std;
class base{
    public:
        base(){cout<<"con\n";}
        virtual ~base(){cout<<"decon\n";}
};
class derive:public base{
    public:
        derive(){cout<<"con1\n";}
        ~derive(){cout<<"decon1\n";}

};
int main(){
    derive * d = new derive();
   // delete d;
    cout<<endl;
    base* b = d;
    delete b;
    return 0;
}
