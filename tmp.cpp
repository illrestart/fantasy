#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int foo(int x){
    return x&-x;
}
void func(int n){
    stack<int> stk;
    int t = 1;
    //cout<<n & t<<endl;
    for(int i=0;i<31;++i,n=n>>1){
        if((n & t) == 0) stk.push(0);
        else if((n & t) == 1) stk.push(1);
        else cout<<"error"<<endl;
    }

    while(!stk.empty()){
        cout<<stk.top();
        stk.pop();
    }
}
int fun1(){
    char str1[] = "hello world";
    char str2[] = "hello world";
    if(str1 == str2) cout<<"yes"<<endl;
    cout<<*str1<<" "<<*str2<<endl;
    cout<<&str1[0]<<" "<<&str2[0]<<endl;
}
void fun2(int* p1,int* p2){
    int* i;
    for(i=p1;*i <6 ;++i){}
    cout<<i - p1;

}
void fun3(int a[]){
    cout<<sizeof(a)<<endl;
}
int main(){
     int a[] = {0,1,2,5,6,7,8,9};
     int b[10] = {1,2,3,4,5,6,7,8};
     //fun2(a,b);
     fun3(b);
     cout<<sizeof(a)<<endl;
     //cout<<NULL<<endl;
     //fun1();

     return 0;
}