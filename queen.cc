#include <iostream>
using namespace std;
#define Max 100
int flag = 0;
int isCorrect(int i,int j,int (*Q)[Max],int num){
    int k,z;
    for(k=0;k<num;++k)
        if(Q[j][k] == 1 && k != i) return 0;

    for(k=0;k<num;++k)
        if(Q[k][i] == 1 && k != j) return 0;

    for(k=i-1,z=j-1;k>=0&&z>=0;--k,--z)
        if(Q[z][k] == 1 && z!=j && k!=i) return 0;

    for(k=i+1,z=j+1;k<num&&z<num;++k,++z)
        if(Q[z][k] == 1 && z!=j && k!=i) return 0;

    for(k=i+1,z=j-1;k<num&&z>=0;++k,--z)
        if(Q[z][k] == 1 && z!=j && k!=i) return 0;

    for(k=i-1,z=j+1;k>=0&&z<num;--k,++z)
        if(Q[z][k] == 1 && z!=j && k!=i) return 0;


    return 1;
}
void Print(int (*Q)[Max],int num){
    for(int i=0;i<num;++i){
        for(int j=0;j<num;++j)
                cout<<Q[i][j]<<" ";
        cout<<endl;
    }
}
void Queen(int (*Q)[Max],int num,int t){
    if(t == num){
        Print(Q,num);
        cout<<endl;
        //flag = 1;
        return;
    }
    else{
        for(int i=0 ; i<num; ++i){
            if(isCorrect(i,t,Q,num)){
               Q[t][i] = 1;
               Queen(Q,num,t+1);
                Q[t][i] = 0;

            }
        }
    }
}
void initQ(int (*Q)[Max],int num){
 //   cout<<"in\n";
    for(int i=0;i<num;++i)
        for(int j=0;j<num;++j)
            Q[i][j] = 0;
}
int main(){
    int Q[Max][Max];
    int num;
    while(cin>>num){
        initQ(Q,Max);
        Queen(Q,num,0);
    }
 //   Print(Q,num);

    return 0;

}
