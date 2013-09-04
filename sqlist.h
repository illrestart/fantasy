#include <iostream>
#include <stdlib.h>
using namespace std;

//template <class U>
class Elem{ 
	public:
		Elem();
		int m_elem;
		Elem *next;
};

//template <class T>
class sqlist{
	public:
		sqlist();
		~sqlist();

		void insertSqlist(int,int);
		void deleteSqlist(int);
		Elem * findPre(int);
		void showMenu();
		void showResult();
		void chooseM(int);

		int m_length;
		Elem *m_head;
		Elem *m_tail;
};


sqlist::sqlist()
	:m_length(0),m_head(NULL)
{}
sqlist::~sqlist(){
	Elem *e;
	e = m_head;
	while(m_head != NULL){
		m_head = m_head->next;
		delete(e);
		e = m_head;
	}
}
Elem::Elem()
	: next(NULL)
{}

//template <typename T>
void sqlist::insertSqlist(int pos,int elem){
	if(m_length + 1 < pos || pos < 1) exit(0);
	else{
		if(m_head == NULL){
			Elem *e = new Elem;
			e->m_elem = elem;
			m_head = e;
			m_tail = e;
			++m_length;
		}
		else if(m_head != NULL && pos == 1){
			Elem *e = new Elem;
			e->m_elem = elem;
			e->next = m_head;
			m_head = e;
			++m_length;
		}
		else if(pos == m_length + 1){
			Elem *e = new Elem;
			e->m_elem = elem;
			m_tail->next = e;
			m_tail = e;
			++m_length;
		}
		else{
			Elem *e = new Elem;
			e->m_elem = elem;
			Elem * pre;
			pre = findPre(pos);
			e->next = pre->next;
			pre->next = e;
			++m_length;
		}
	}
}

void sqlist::deleteSqlist(int pos){
	if(pos > m_length + 1 || pos < 1) exit(0);
	else{
		if(m_length == 1){
			delete(m_head);
			m_head = NULL;
			m_tail = NULL;
			--m_length;
		}
		else if(pos == 1 && m_length > 1){
			Elem *e;
			e = m_head;
			m_head = m_head->next;
			delete(e);
			--m_length;
		}
		else if(pos == m_length && m_length > 1){
			Elem *pre = findPre(pos);
			Elem *e;
			e = m_tail;
			m_tail = pre;
			m_tail->next = NULL;
			delete(e);
			--m_length;
		}
		else{
			Elem *pre = this->findPre(pos);
			Elem *p = pre->next;
			pre->next = p->next;
			delete(p);
			--m_length;
		}
	}
}

Elem * sqlist::findPre(int pos){
	Elem *l = this->m_head;
	for(int i = 1; i <= m_length ; ++i){
		if(i == pos - 1) return l;
		else l = l->next;
	}
}

void sqlist::showMenu(){
	int c;
	do{
		cout<<"++++++++++++++++++++++"<<endl;
		cout<<"+1.insert            +"<<endl;
		cout<<"+2.delete            +"<<endl;
		cout<<"+3.show              +"<<endl;
		cout<<"+4.exit              +"<<endl;
		cout<<"++++++++++++++++++++++"<<endl;
		cin>>c;
		chooseM(c);
	}while(c != 4);
}

void sqlist::chooseM(int c){
	int n,p;
	switch(c){
		case 1:
			cout<<"insert(pos,val):";
			cin>>p>>n;
			insertSqlist(p,n);
			break;
		case 2:
			cout<<"delete(pos):";
			cin>>p;
			deleteSqlist(p);
			break;
		case 3:
			showResult();
			break;
		default:
			this->~sqlist();
			break;
	}
}

void sqlist::showResult(){
	Elem *l;
	l = this->m_head;
	while(l != NULL){
		cout<<l->m_elem<<" ";
		l = l->next;
	}
	cout<<endl;
}
