#include <iostream>
using namespace std;
int A(int m,int n){
    if(m==0) return n+1;
    else if(m>0 && n==0) return A(m-1,1);
    else if(m>0 && n>0 )return A(m-1,A(m,n-1));
   // cout<<m<<" "<<n<<endl;
}
int main(){
    cout<<A(3,8);
}
