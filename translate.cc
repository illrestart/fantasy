#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;
void printqueue(queue<char> q){
	cout<<"------\n";
	while(!q.empty()){
		cout<<q.front();
		q.pop();
	}
	cout<<"------\n";
}
void printstack(stack<char> q){
	cout<<"++++++++\n";
	while(!q.empty()){
		cout<<q.top();
		q.pop();
	}
	cout<<"+++++\n";
}
void translate(queue<char> s){
	char c;
	char tmp;
	if(!s.empty()){
		c = s.front();
		s.pop();
		if(c == 'A') cout<<"sae";
		else if(c == 'B'){
			s.push('t');
			s.push('A');
			s.push('d');
			s.push('A');
		}
		else if(c == '('){
			tmp = s.front();
			s.pop();
			queue<char> tmp_s;
			stack<char> st;
			for(c = s.front(),s.pop(); c != ')';c = s.front(),s.pop()){
				st.push(c);
			}
			//printstack(st);
			for(c = st.top(),st.pop(); !st.empty() ; c = st.top(),st.pop()){
				tmp_s.push(tmp);
				tmp_s.push(c);
			}
			tmp_s.push(tmp);
			tmp_s.push(c);
			tmp_s.push(tmp);
			//printqueue(tmp_s);
			translate(tmp_s);
		}
		else cout<<c;
	translate(s);
	}
}
int main(){
	queue<char> s;
	char c;
	for(cin>>c; c != '#'; cin>>c){
		s.push(c);
	}
	translate(s);
}
