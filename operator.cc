#include <iostream>
using namespace std;

class A{
    public:
        A();
        A(int,int);
        A operator+(A);
        bool operator==(const A&,const A&);

        int m_a;
        int m_b;
};
A::A()
    :m_a(0),
    m_b(0)
{
}
A::A(int t,int p)
    :m_a(t),
    m_b(p)
{
}
A A::operator+(A a){
    A c;
    c.m_a = this->m_a + a.m_a;
    c.m_b = this->m_b + a.m_b;
    return c;
}
bool A::operator==(const A& a,cpmst A& b){

}
void print(A a){
    cout<<a.m_a<<" "<<a.m_b<<endl;
}
int main(){
    A a;
    A b(1,2);
    A c = a + b;
    print(c);
    c = c + c;
    print(c);
    cout<<1+2+3<<endl;
    return 0;
}
