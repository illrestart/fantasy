#include "iostream"
#include "sqlist.h"
using namespace std;
int menu(){
	int l;
	cout<<"+++++++++++++++++++++++"<<endl;
	cout<<"+1.list               +"<<endl;
	cout<<"+2.exit               +"<<endl;
	cout<<"+++++++++++++++++++++++"<<endl;
	cin >> l;
	return l;
}
void chooseM(int m){
	sqlist sq;
	switch(m){
		case 1:
			sq.showMenu();
			break;
		default:
			break;
	}
}
int main()
{
	int m;
	do{
	m =	menu();
	chooseM(m);
	}while(m != 2);

}
