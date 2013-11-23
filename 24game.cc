#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <vector>
#include <sstream>
using namespace std;
ofstream of;
class value{
    public:
        value();
        void getVal(string);
        void playGame();
        int isEmpty();
        double getSumValue(double,double,int);
        void InVector(double,int);
        void DeVector();
        void init();
        void getResult();
        void printQueue();


        double val[4];
        int status[4];
        double sumValue;
        int m_flag;
        queue<double> m_queue;
        vector<double> m_vec;

};
template<typename T>
void show(T v[]){
    cout<<"show======"<<endl;
    for(int i=0;i<4;++i) cout<<v[i];
    cout<<endl;
}
value::value():m_flag(0){
    for(int i=0;i<4;++i){
        val[i]=0;
        status[i]=0;
    }
}
void value::getVal(string str){
    istringstream is(str);
    string tmp;
    for(int i=0;is>>tmp;++i){
        if(tmp == "A") val[i]=1;
        else if(tmp == "2") val[i]=2;
        else if(tmp == "3") val[i]=3;
        else if(tmp == "4") val[i]=4;
        else if(tmp == "5") val[i]=5;
        else if(tmp == "6") val[i]=6;
        else if(tmp == "7") val[i]=7;
        else if(tmp == "8") val[i]=8;
        else if(tmp == "9") val[i]=9;
        else if(tmp == "10") val[i]=10;
        else if(tmp == "J") val[i]=11;
        else if(tmp == "Q") val[i]=12;
        else if(tmp == "K") val[i]=13;
    }
}
int value::isEmpty(){
    for(int i=0;i<4;++i)
        if(status[i] == 0)
            return 0;
    return 1;
}
double value::getSumValue(double sum,double v,int signal){
    if(sum == 0){
        of<<sum<<"+-*/"<<v<<" "<<v<<endl;
        return v;
    }
    else{
        switch(signal){
            case 0:
                of<<sum<<"+"<<v<<" "<<sum+v<<endl;
                return sum+v;
            case 1:
                of<<sum<<"-"<<v<<" "<<sum-v<<endl;
                return sum-v;
            case 2:
                of<<sum<<"*"<<v<<" "<<sum*v<<endl;
                return sum*v;
            case 3:
                of<<sum<<"/"<<v<<" "<<sum/v<<endl;
                return sum/v;
        }
    }
}
void value::InVector(double v,int signal){
    if(m_vec.size()==0){
        m_vec.push_back(v);
    }
    else{
        m_vec.push_back(((double)(signal+100)));
        m_vec.push_back(v);
    }
}
void value::DeVector(){
    if(m_vec.size()==1){
        m_vec.pop_back();
    }
    else{
        m_vec.pop_back();
        m_vec.pop_back();
    }
}
void value::playGame(){
    double tmp,tmp1;
    if(isEmpty()){
        if(sumValue == 24){
            m_flag = 1;
        }
    }
    else{
        for(int i=0;i<4&&m_flag==0;++i){//num
            if(status[i] == 0){
                status[i] = 1;
                for(int j=0;j<4&&m_flag==0;++j){//symbol
                    tmp = sumValue;
                    sumValue = getSumValue(sumValue,val[i],j);
                    for(int k=0;k<4;++k) of<<status[k]<<" ";
                    of<<endl;
                    InVector(val[i],j);
                    of<<sumValue<<endl;
                    playGame();
                    if(m_flag == 1) break;
                    sumValue = tmp;
                    DeVector();
                }
                status[i] = 0;
            }
        }
    }
}
void value::init(){
    for(;m_vec.size()>0;m_vec.pop_back()){}
    for(int i=0;i<4;++i){
        val[i]=0;
        status[i]=0;
    }
    m_flag=0;
    sumValue=0;
}
void value::getResult(){
    cout<<"(((";
    double tmp;
    for(int i=0;m_vec.size()>0;++i,m_vec.erase(m_vec.begin())){
        tmp = m_vec.front();
        if(tmp>=2 && tmp<=10) cout<<tmp;
        else if(tmp == 1) cout<<"A";
        else if(tmp == 11) cout<<"J";
        else if(tmp == 12) cout<<"Q";
        else if(tmp == 13) cout<<"K";
        else if(tmp == 100)cout<<"+";
        else if(tmp == 101)cout<<"-";
        else if(tmp == 102)cout<<"*";
        else if(tmp == 103)cout<<"/";

        if(i!=0 && i%2==0) cout<<")";
    }
}
void value::printQueue(){
    if(m_queue.size() == 0 )cout<<"empty"<<endl;
    else{
        for(;m_queue.size()!=0;m_queue.pop()){
            cout<<m_queue.front();
        }
    }
}
int main(){
    ifstream in;
    string file_string;
    in.open("24game.txt");
    of.open("output.txt");
    value v;
    while(!in.eof()){
        v.init();
        getline(in,file_string);
        cout<<file_string<<endl;
        v.getVal(file_string);
        v.playGame();
    //    v.printQueue();
        if(v.m_flag == 1) v.getResult();
    }
    return 0;
}
