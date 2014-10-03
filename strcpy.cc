#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
void strcpy(char* dest,char* src){
    char* head = dest;
    while(*src != '\0'){
        *dest++ = *src++;
    }
    dest = head;
}

int main(){
    char dest[10];
    char src[] = "abcdefg";
    strcpy(dest,src);
    cout<<dest;
    return 0;
}
