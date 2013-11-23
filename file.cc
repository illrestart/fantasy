#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ofstream file;
    string file_name;
    cin>>file_name;
    cout<<"file name :"<<file_name<<endl;
    file.open(file_name.c_str());
    char c;
    cin.get(c);
    for(cin.get(c);c != '\n';cin.get(c)){
        file.put(c);
    }
    file.close();
    return 0;
}
