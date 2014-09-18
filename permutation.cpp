#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
void permulation(char a[],int flag[],int len,vector<char> vec){
    if(vec.size() == len){
        for(vector<char>::iterator iter = vec.begin();iter!=vec.end();++iter)
            cout<<*iter<<" ";
        cout<<endl;
    }else{
    for(int i=0;i<len;++i){
        if(flag[i] == 0){
            vec.push_back(a[i]);
            flag[i] = 1;
            permulation(a,flag,len,vec);
            flag[i] = 0;
            vec.pop_back();
        }
    }
    }
}
int main(){
    char a[3] = {'a','b','c'};
    vector<char> vec;
    int flag[3]={0};
    //a[] = "abc";
    cout<<sizeof(a)<<endl;
    permulation(a,flag,3,vec);
    /*for(int i=0;i<sizeof(a);++i){
        if(flag[i] == 0){
            vec.push_back(a[i]);
            flag[i] = 1;
            permulation(a,flag,sizeof(a),vec);
            flag[i] = 0;
            vec.pop_back();
        }
    }*/
    return 0;
}
