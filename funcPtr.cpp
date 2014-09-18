#include <iostream>
using namespace std;
int max(int x,int y){return x>y?x:y;}
void func(int (*p)(int,int)){
    cout<<(*p)(8,9);
}
void fun(){
    int (*ptr)(int,int);
    ptr = max;
    func(ptr);
}
typedef void (*FuncPtr)(int);
void turn(int n){
    for(int i=0;i<31;++i,n>>=1){
        cout<<(n&(0x0001));
    }
}
void fun1(){
    void (*p)(int);
    p=turn;
    (*p)(15);
}
int main(){
    fun();
    cout<<endl;
    fun1();
    return 0;
}
