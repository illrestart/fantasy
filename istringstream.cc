#include <iostream>
#include <sstream>
#include <string>
using namespace std;
void test_istringstream(){
    string str = "liuming 23 student computer";
    istringstream instr(str);
    string name;
    int age;
    string occupation;
    string majorin;
    instr>>name>>age>>occupation>>majorin;
    cout<<name<<age<<occupation<<majorin;
}
void test_ostringstream(){
    ostringstream ostr;
    string name = "mxx";
    int age = 22;
    string occupation = "student";
    string majorin = "computer science";
    ostr<<name<<age<<occupation<<majorin;
    string str = ostr.str();
    cout<<str;
}
int main(){
    test_istringstream();
    test_ostringstream();
    return 0 ;

}
