#include <iostream>
using namespace std;
class ConstTry{
public:
    int m_data;
    ConstTry(int data):
        m_data(data){
        }
    int top()const;
    int bap();
};
int ConstTry::bap(){
    return m_data;
}
int ConstTry::top() const{
    return m_data;
}
int main(){
    const ConstTry ct(10);
    cout<<ct.top();
    return 0;
}
