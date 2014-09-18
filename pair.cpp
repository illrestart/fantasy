#include <iostream>
#include <utility>
#include <map>
#include <string>
#include <set>
using namespace std;
void func(pair<int,char> p){
    map<int,char> m;
    m[p.first] = p.second;
    map<int,char>::iterator m_it;
    for(m_it = m.begin();m_it != m.end() ;++m_it){
        cout<<m_it->first<<" "<<m_it->second;
    }
}
void func1(){
    map<string,string> m;
    m.insert(make_pair("gogogo","mbkdsasd"));
    cout<<endl;
    string c = m["gogogo"];
    cout<<c<<endl;
}
void func2(){
    int a[] = {66,3,22,23,54,12,54};
    set<int> ss;
    for(int i=0;i<sizeof(a)/4;++i){
        ss.insert(a[i]);
    }
    typedef set<int>::iterator sIter;
    for(sIter iter=ss.begin();iter != ss.end();++iter){
        cout<<*iter<<endl;
    }
}
int main(){
    int n =1;
    char c = 'c';
    pair<int,char> p;

    p = make_pair(n,c);
    cout<<p.first<<p.second;
    func(p);
    func1();
    func2();
    return 0;
}
