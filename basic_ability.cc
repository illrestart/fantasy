#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <fstream>
using namespace std;
#define MAX 1024

ofstream outStream;

//outStream.open("tmpsave.txt");

void ascii_count(){
    int space=0,table=0,enter=0;
    char c;
    scanf("%c",&c);
     while(~scanf("%c",&c)){
        switch(c){
            case 32: space++;break;
            case 9:table++;break;
            case 10:enter++;break;
            default:break;
        }
    }
    cout<<space<<" "<<table<<" "<<enter<<endl;
}
void calc_ascii(){
    char c;
    while(cin>>c){
        cout<<(int)c<<endl;
    }
}
void fileIO(){
}
void deTobi(){
    int t,i=0;
    int a[10];
    while(cin>>t){
        while(t/2 != 0){
            a[i++] = t%2;
            t = t/2;
         }
         a[i] = t%2;
         for(;i>=0;--i) cout<<a[i]<<" ";
         cout<<endl;
         i=0;
    }
}
void reverse(){
    char c;
    //scanf("%c",&c);
    //cin>>c;//cin会自动过滤掉空格换行
    c = cin.get();
    if(c != '\n'){
        reverse();
        cout<<c;
    }
}
double wheat(int i){
    return i<63?(pow(2,i)+wheat(i+1)):pow(2,i);
}
int gcd(int a,int b){
    int c = a%b;
    if(c==0)return b;
    return c>b?gcd(c,b):gcd(b,c);
}
int isPrim(int i){
    if(i == 1) return 0;
    else{
        for(int j=2;j<i;++j)
            if(i%j == 0) return 0;
        return 1;
    }
}
int goldbach(int num){
    for(int i=1;i<num;++i){
        if(isPrim(i)&&isPrim(num-i)){
            cout<<num<<"="<<i<<"+"<<num-i<<endl;
            return 1;
        }
    }
    cout<<num<<"= error"<<endl;
    return 0;
}
int flag = 0;

int marry(int (*match)[3],int i,int j,int k){
    if(i!=j&&j!=k&&i!=k)
        if(match[0][0]!=1&&match[2][0]!=1&&match[2][2]!=1){
            return 1;
        }
   return 0;
}
vector<char> vec;
void perm(char *save,int *tmp,int n){
    if(vec.size() == n){
        for(vector<char>::iterator iter = vec.begin(); iter != vec.end();++iter)
            cout<<*iter<<" ";
        cout<<endl;
    }
    else{
        for(int i = 0; i< n; ++i){
            if(tmp[i] == 0){
                vec.push_back(save[i]);
                tmp[i] = 1;
                perm(save,tmp,n);
                tmp[i] = 0;
                vec.pop_back();
            }
        }

    }
}
int facSum(int n){
    int sum=0;
    for(int i = 1; i < n ; ++ i){
        if(n%i == 0)
            sum += i;
    }
    return sum;
}
void friendly(){
    int b=0;
    for(int i = 2 ; i < 3000 ; ++i){
        b = facSum(i);
        if((facSum(b) == i) && b != i && b>1 && b <= 3000){
            cout<<"<"<<i<<" "<<b<<">"<<endl;
        }
    }
}
int squareCount = 0;
vector<int> squareVec;
int isSquare(int n){
    int i = sqrt(n);
    if(i*i == n) return 1;
    else return 0;
}
void fourSquare(int n){
    if(isSquare(n)&&squareCount<4){
        flag = 1;
        squareVec.push_back(sqrt(n));
        for(vector<int>::iterator iter = squareVec.begin(); iter != squareVec.end();++iter)
            cout<<*iter<<" ";
        cout<<endl;
        squareVec.clear();
    }
    else if(flag == 0 && squareCount<4){
        for(int i=1;i<n&&flag==0;++i)
            if(isSquare(i)){
           //     outStream<<squareCount<<"---"<<i<<endl;
                squareVec.push_back(sqrt(i));
                squareCount++;
                fourSquare(n-i);
                squareCount--;
                if(squareVec.size() != 0) squareVec.pop_back();
            }

    }

}
int main(){
    int n;
    char c;
    int a,b,d;
    cin>>n;
    switch(n){
        case 1:
            ascii_count();
            break;
        case 2:
            calc_ascii();
            break;
        case 3:
            fileIO();
            break;
        case 4:
            deTobi();
            break;
        case 5:
            cin.get();
            reverse();
            break;
        case 6:
            cout<<wheat(0);
            break;
        case 7:
            while(cin>>a>>b){
                cout<<((a>b)?gcd(a,b):gcd(b,a))<<endl;
            }
            break;
        case 8:
            while(cin>>a>>b){
                cout<<a*b/(a>b?gcd(a,b):gcd(b,a))<<endl;
            }
            break;
        case 9:
            for(a=2;a<100;++a)
                goldbach(a);
            break;
        case 10:
            int match[3][3];
            int i,j,k;
            for(i=0;i<3;++i)
                for(j=0;j<3;++j)
                    match[i][j] = 0;

            for(i=0;i<3;++i){
                match[0][i] = 1;
                for(j=0;j<3;++j){
                    match[1][j] = 1;
                    for(k=0;k<3;++k){
                        match[2][k] = 1;
                        if(marry(match,i,j,k)){
                            for(a=0;a<3;++a)
                                for(b=0;b<3;++b)
                                    if(match[a][b] == 1){
                                        cout<<(char)(a+'A')<<"--"<<(char)(b+'X')<<endl;
                                    }
                        }
                        match[2][k] = 0;
                    }
                match[1][j] = 0;
                }
            match[0][i] = 0;
            }
            break;
        case 11:
            char c;
            char save[MAX];
            int tmp[MAX];
            n=0;
            while(1){
                for(cin.get(c);c!='\n';cin.get(c)){
                    if(c != ' '){
                        save[n] = c;
                        tmp[n] = 0;
                        n++;
                    }
                }
                for(int j=0;j<n;++j){
                    vec.push_back(save[j]);
                    tmp[j] = 1;
                    perm(save,tmp,n);
                    tmp[j]=0;
                    vec.pop_back();
                }
            }
            break;
        case 12:
            friendly();
            break;
        case 13:
            outStream.open("tmpsave.txt");
            while(cin>>n){
                flag = 0;
                squareCount = 0;
                fourSquare(n);
            }
            break;
        default:break;
    }

}
