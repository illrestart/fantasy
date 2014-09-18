#include <iostream>
using namespace std;
//
void BubbleSort(int a[],int n){
    int flag = 0;
    for(int i=0;i<n && flag == 0;++i)
        for(int j=0;j<n-i;++j)
            if(a[j]>a[j+1])
                swap(a[j],a[j+1]);
}
//
int Partition(int a[],int head,int tail){
    int base = a[head];
    while(head < tail){
        while(head < tail && a[tail] > base)--tail;
        a[head] = a[tail];
        while(head<tail && a[head] < base) ++head;
        a[tail] = a[head];
    }
    a[head] = base;
    return head;
}
int QuickSort(int a[],int head,int tail){
    if(head < tail){
        int p = Partition(a,head,tail);
        QuickSort(a,head,p-1);
        QuickSort(a,p+1,tail);
    }
}
void selectSort(int a[],int n){
    int small;
    for(int i=0;i<n;++i){
        small = i;
        for(int j=i+1;j<n;++j){
            if(a[small] > a[j])small = j;
        }
        if(small != i) swap(a[small],a[i]);
    }
}

void HeapAdjust(int a[],int s,int n){
    for(int j = s*2 + 1; j < n; j = s*2 + 1){
        if(j+1 < n && a[j] < a[j+1] ) ++j;
        if(a[s] < a[j]){
                swap(a[s],a[j]);
                s = j;
        }
        else break;
    }
}
void headSort(int a[],int n){
    int t,i,j;
    for(i=n/2-1;i>=0;--i)
        HeapAdjust(a,i,n);
    for(i=n-1;i>=0;--i){
        swap(a[i],a[0]);
        HeapAdjust(a,0,i);
    }
}
void InsertSort(int a[],int n){
    int j;
    for(int i=1;i<n;++i){
        int tmp = a[i];
        for(j=i-1;j>=0;--j){
            if(tmp < a[j])
                a[j+1] = a[j];
        }
        a[j+1] = tmp;
    }
}
void ShellSort(int a[],int n){
    int d = n/2;
    while(d>=1){
        for(int i = d; i< n ; ++i){
            int tmp = a[i];
            for(int j = i-d; j >= 0; j-=d){
                if(a[j] > tmp) a[j+d] = a[j];
            }
            a[j+d] = tmp;
        }
        d/=2;
    }
}
void Merge(int a[],int r[],int start,int mid,int last){
    int i,j,k;
    for(i=start,j=mid+1,k=start; i<=mid && j<=last;){
        if(a[i]<a[j]) r[k++]=a[i++];
        else r[k++]=a[j++];
    }
    while(i<=mid) r[k++]=a[i++];
    while(j<=last) r[k++]=a[j++];
}
void MergeAdujest(int a[],int r[],int n,int len){
    int last;
    for(int beg = 0;beg+len<n;){
        last = beg + len*2 -1;
        if(last >= n) last = n-1;
        Merge(a,r,beg,beg+len-1,last);
        beg = last + 1;
    }
    if(beg < n){
        while(beg < n){
            r[beg] = a[beg];
            beg++;
        }
    }
}
void MergeSort(int a[],int n){
    int len = 1;
    int *p = (int*)malloc(sizeof(int)*n);
    int f = 0;
    while(len < n){
        if(f) MergePass(a,p,n,len);
        else MergePass(p,a,n,len);
        len*=2;
        f = 1-f;
    }
    if(f){
        for(f = 0;f<n;++f)
            a[f]=p[f];
    }
    free(p);
}
int main(){
    return 0;
}
