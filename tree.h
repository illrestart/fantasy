#include <iostream>
#include <string.h>
using namespace std;
class tree{
	public:
		tree():lch(NULL),rch(NULL){}

		char val;
		tree * lch;
		tree * rch;
};
class treehelper{
	public:
	treehelper():m_len(0){
		m_tree = NULL;
	}
	void createTree();
	void deleteTree(tree *);
	void preOrder(tree *);
	void inOrder(tree *);
	void posOrder(tree *);
	tree * init(int,int,int,int);
	void showMenu();
	void chooseM(int);
	int find(char,int,int);

	char tmpa[100],tmpb[100];

	tree * m_tree;
	int m_len;
};
void treehelper::chooseM(int c){
	switch(c){
		case 1:
			createTree();
			preOrder(m_tree);
			break;
		case 2:
			int str;
			cout<<"1.preorder\n2.inorder\n3.posorder\n";
			cin>>str;
			tree *p;
			p = m_tree;
			cout<<m_tree<<" "<<p<<endl;
			switch(str){
				case 1:
					preOrder(p);
					break;
				case 2:
					inOrder(p);
					break;
				case 3:
					posOrder(p);
				default:
					break;
			}
			break;
		case 3:
			deleteTree(m_tree);
			break;
		default:
			break;
	}
}
void treehelper::deleteTree(tree * t){ 
	if(t->lch == NULL && t->rch == NULL) delete(t);
	else if(t->lch == NULL && t->rch != NULL) {
		deleteTree(t->rch);
		delete(t);
	}
	else if(t->lch != NULL && t->rch == NULL){
		deleteTree(t->lch);
		delete(t);
	}
	else{
		deleteTree(t->lch);
		deleteTree(t->rch);
		delete(t);
	}
	m_len = 0;
}
void treehelper::showMenu(){
	int c;
	do{
	cout<<"++++++++++++++"<<endl;
	cout<<"+1.create    +"<<endl;
	cout<<"+2.display   +"<<endl;
	cout<<"+3.delete    +"<<endl;
	cout<<"+0.exit      +"<<endl;
	cout<<"++++++++++++++"<<endl;
	cin>>c;
	chooseM(c);
	}while(c!=0);
}
int treehelper::find(char c,int lf,int ri){
	for(;lf<ri;++lf){
		if(tmpa[lf] == c)return lf;
  	}
	return -1;
}  
tree * treehelper::init(int lf,int ri,int lf1,int ri1){
	if(lf1 >= m_len || lf >= ri || lf1 >= ri1){return NULL;}
	else{ 
		int loc=find(tmpb[lf1],lf,ri);
		if(loc != -1){
			tree * root = new tree;
			root->val = tmpb[lf1];
			root->lch = init(lf,loc,lf1+1,lf1+1+(loc-lf));
			root->rch = init(loc+1,ri,ri1-(ri-(loc+1)),ri1);
			return root;
		}
		else{
			cout<<"can't get loc "<<endl;
			return NULL;
		}
	}
}
void treehelper::preOrder(tree * t){
	if( t == NULL){}
	else{
		cout<<t->val<<" ";
		preOrder(t->lch);
		preOrder(t->rch);
	}
}
void treehelper::inOrder(tree * t){
	if( t == NULL){}
	else{
		inOrder(t->lch);
		cout<<t->val<<" ";
		inOrder(t->rch);
	}
}
void treehelper::posOrder(tree * t){
	if( t == NULL){}
	else{
		posOrder(t->lch);
		posOrder(t->rch);
		cout<<t->val<<" ";
	}
}
void treehelper::createTree(){
	char tmp;
	int i;
	cout<<"input preorder and inorder sequence:"<<endl;
	cout<<"inorder:";
	cin>>tmp;
	for(i=0;tmp != '#';i++){tmpa[i] = tmp;cin>>tmp;}
	cout<<"preorder:";
	cin>>tmp;
	for(i=0;tmp != '#';i++){tmpb[i] = tmp;cin>>tmp;}
	m_len = i;

	m_tree = init(0,i,0,i);
}

