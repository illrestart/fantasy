#include <iostream>
using namespace std;
class A{
    public:
        A():num(10){}
        virtual int getNum();
        void print();
    private:
        int num;
};
void A::print(){
    cout<<"this is A"<<endl;
}
int A::getNum(){
    return this->num;
}
class B:public A{
    public:
        virtual int getNum();
};
int B::getNum(){
    return 20;
}
void func(A a){
    a.print();
}
int main(){
    A a;
    B b;
    cout<<a.getNum()<<b.getNum();
    b.print();
    func(b);
    return 0;

}
