#include <iostream>
using namespace std;
int mini(int a[],int len){
    int minN = a[0];
    for(int i=1;i<len;++i){
        if(a[i] < minN)
            minN = a[i];
    }
    return minN;
}
int LIS(int a[],int len){
    int* MaxV = new int[len+1];
    //cout<<mini(a,len);
    MaxV[0] = mini(a,len) - 1;
    MaxV[1] = a[0];

    int* LIS = new int[len];
    for(int i=0;i<len;++i){
        LIS[i] = 1;
    }
    int nMaxLIS = 1;
    for(int i=1; i< len; ++i){
        int j;
        for(j = nMaxLIS;j>=0;--j){
            if(a[i] > MaxV[j]){
                LIS[i] = j+1;
                break;
            }
        }

        if(LIS[i] > nMaxLIS){
            nMaxLIS = LIS[i];
            MaxV[LIS[i]] = a[i];
        }
        else if(MaxV[j] < a[i] && a[i] < MaxV[j+1]){
            MaxV[j+1] = a[i];
        }
    }
    return nMaxLIS;

}
int LIS1(int a[],int len){
    int* nmax = new int[len];
    int maxL = 0xffffffff;
    for(int i=0;i<len;++i){
        nmax[i] = 1;
        for(int j = 0;j<i;++j){
            if(a[i] > a[j] && nmax[j]+1 > nmax[i]){
                nmax[i] = nmax[j] +1;
            }
        }
        if(nmax[i] > maxL) maxL = nmax[i];
    }
    return maxL;
}
int main(){
    int a[] = {1,1,2,3,4,5,6,7};
    cout<<LIS1(a,sizeof(a)/4);
}
