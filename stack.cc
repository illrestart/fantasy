#include <iostream>
using namespace std;
template <typename T>
class Elem{
	public:
		T val;
		Elem<T> * next;
};
template <typename T>
class stack{
	public:
		stack():elem(NULL){}

		void push(T);
		T pop();
		Elem<T> * elem;
};
template <typename T>
void stack<T>::push(T v){
	Elem<T> *e = new Elem<T>;
	e->val = v;
	if(elem == NULL)e->next = NULL;
	else e->next = elem;
	elem = e;
}
template <typename T>
T stack<T>::pop(){	
	if(elem != NULL){
		Elem<T> *e = elem;
		elem = elem->next;
		cout<<e->val;
		T v = e->val;
		delete(e);
		return v;
	}
	else{
		cout<<"empty stack"<<endl;
		return 0;
	}
}
int main(){
	stack<int> s;
	int tmp,tmp1;
	while(cin>>tmp){
		if(tmp == 1){
			cin>>tmp1;
			s.push(tmp1);
		}
		else if(tmp == 2){
			s.pop();
		}
	}
	return 0;
}
