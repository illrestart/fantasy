#include <iostream>
#include <math.h>
#include <unistd.h>
#include <vector>
#include <stack>
#include <stdio.h>
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
<<<<<<< HEAD
void func4(){
	for(int i=0;i< pow(10,4);++i){
		cout<<i<<endl;
		sleep(1);
	}
	cout<<"done"<<endl;
}
class A{
	public:
		char a;
		//double c;
		//float b;
		//virtual void func();
};
class B : public A{
	public:
		//int d;
		int b;
		/*void func(){
		int c;
		}*/
};
=======

int isTrue(int t){
    if(t)
        cout<<"isTrue";
    else
        cout<<"isFalse";
    return true;
}
void func5(char c[100]){
    cout<<sizeof(c);
}
void func4(){
    char c[] = "abcd";
    char* p = c;
    char c1[100] = {0};
   // cout<<sizeof(c1)<<" "<<sizeof(p);
    printf("%s %s %s",c,c);
    //func5(p);
}
>>>>>>> 8e14dba823376a5e3ba3e33e7184238b8efba499
int main(){
     int a[] = {0,1,2,5,6,7,8,9};
     int b[10] = {1,2,3,4,5,6,7,8};
	 string* str = new string[10];
	 int *i[10]; 

     //fun2(a,b);
<<<<<<< HEAD
//     fun3(b);
  //   cout<<sizeof(a)<<endl;
     //cout<<NULL<<endl;
     //fun1();
	func4();
	 //cout<<sizeof(A)<<endl;
	 //cout<<sizeof(B)<<endl;
=======
     //fun3(b);
     //cout<<sizeof(a)<<endl;
     ////cout<<NULL<<endl;
     //fun1();
     //cout<<isTrue(-1);
     func4();
>>>>>>> 8e14dba823376a5e3ba3e33e7184238b8efba499
     return 0;
}
