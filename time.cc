#include <iostream>
#include <stdio.h>
#include <time.h>
#include <Windows.h>
using namespace std;
int main(){
    //clock use to count the time
    clock_t start,finish;
    start = clock();
    for(int i=0;i<1000000;++i){}
    finish = clock();
    cout<<finish-start<<endl;

    tm* local;
    time_t t;
    while(1){
        t = time(NULL);
        local = localtime(&t);
        printf("%d-%d-%d",local->tm_hour,local->tm_min,local->tm_sec);
        Sleep(1000);
    }
    return 0;
}
