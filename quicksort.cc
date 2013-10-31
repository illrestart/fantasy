#include <iostream>
using namespace std;
void swap(int *a,int i,int j){
    cout<<a[i]<<" "<<a[j]<<" "<<i<<" "<<j<<endl;
    int tmp;
    tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
/*    a[i] = a[i] + a[j];
    cout<<a[i]<<endl;
    a[j] = a[i] - a[j];
    cout<<a[j]<<endl;
    a[i] = a[i] - a[j];
    cout<<a[i]<<endl;*/
 /*   a[i] = a[i]^a[j];
    a[j] = a[i]^a[j];
    a[i] = a[i]^a[j];*/
}
void quickSort(int *a,int head,int tail){
    int i,j;
    if(head < tail){
        i=head;
        j=tail;
        while(1){
            while(a[i] <= a[head] && i <= tail) ++i;
            while(a[j] >= a[head] && j >= head) --j;
            if(i < j) swap(a,i,j);
            else break;
        }
        swap(a,head,i-1);
        quickSort(a,head,i-1);
        quickSort(a,i,tail);
    }
}
void Print(int *a){
    for(int i=0 ; i < 10 ; ++i)
        cout<<a[i]<<" ";
    cout<<endl;
}
int main(){
    int a[10] = {6,4,2,76,9,3,543,73,65,100};
    Print(a);
    quickSort(a,0,9);
    Print(a);
    return 0;
}
