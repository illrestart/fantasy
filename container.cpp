#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;
template <typename T>
void show(T t){
    for(typename T::iterator iter = t.begin(); iter != t.end(); ++iter){
        cout<<*iter<<endl;
    }
}
template <typename T>
void it(T t){
    typename T::iterator iter;
    iter = t.begin();
    cout<<*iter<<endl;
    iter+=4;
    cout<<*iter;
}
void fun(){
    vector<int> vec;
    int n;
    int a[] = {1,5,3,7,4,0,8,6,2,9};
    for(int i=0;i<10;++i){
        vec.push_back(a[i]);
    }
    vec.insert(vec.begin()+5,1024);
    //cout<<vec.max_size();
    //show(vec);
    it(vec);

    cout<<vec.capacity()<<endl;
    vec.reserve(20);
    cout<<vec.capacity()<<endl;
}
void fun1(){
    list<int> li;
    int a[] = {1,5,3,7,4,0,8,6,2,9};
    for(int i=0;i<10;++i){
        li.push_front(a[i]);
    }
    for(list<int>::iterator iter = li.begin();iter != li.end();iter++){
        cout<<*iter<<" ";
    }
}
void fun3(){
    string str = "the boss is handwriting is terrible";
    cout<<*(str.begin()+10)<<endl;
}
int main(){
    //fun();
    //fun1();
    fun3();
    return 0;
}
