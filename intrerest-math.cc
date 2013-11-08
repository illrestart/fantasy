#include <iostream>
using namespace std;
#define MAX 1024
int getMin(int *array,int low,int high){
    int vall,valh;
    if(low <= high){
    if(low == high) return array[low];
    else{
        vall = getMin(array,low,(high-low)/2+low);
        valh = getMin(array,(high-low)/2+low+1,high);
        return vall<valh?vall:valh;
    }
    }
}
int main(){
    int n;
    int array[1024];
    int c,i;
    while(cin>>n){
        if(n == 1){
            for(i=0,cin>>c;c != -1;cin>>c,++i){
                array[i] = c;
            }
            cout<<getMin(array,0,i-1)<<endl;
        }
    }
}
