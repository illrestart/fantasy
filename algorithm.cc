#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <list>
using namespace std;
void func(){
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(5);
    vec.push_back(7);
    int sum = accumulate(vec.begin(),vec.end(),0);
    cout<<sum;
}
bool cmp(const string &str1,const string &str2){
	return str1  < str2;
}
void func1(){
    vector<int> vec;
    vec.resize(5);
    fill_n(vec.begin(),5,1);
    for(int i=0;i<vec.size();++i){
        cout<<vec[i]<<" ";
    }
}
void func2(){
	string str[] = {"fox","red","jumps","trully","trouble"};
	vector<string> vec(str,str+5);
	for(vector<string>::iterator iter=vec.begin();iter!=vec.end();++iter){
		cout<<*iter<<" ";
	}
	sort(vec.begin(),vec.end(),cmp);
	cout<<endl;
	for(vector<string>::iterator iter=vec.begin();iter!=vec.end();++iter){
		cout<<*iter<<" ";
	}
	
}
void func3(){
	list<int> li;
	for(list<int>::size_type i=0;i<4;++i){
		li.push_front(i);
	}
	for(list<int>::iterator i=li.begin();i!=li.end();++i){
		cout<<*i<<endl;
	}

}
int main(){
    //func();
    //func1();
	//func2();
	func3();
    return 0;
}
