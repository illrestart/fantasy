#include <iostream>
using namespace std;
char findChar(char* pHead){
    if(pHead == NULL) return '\0';
    const int hashSize = 256;
    unsigned int pHashTable[hashSize] = {0};
    char* pHashKey = pHead;
    while(*pHashKey != '\0')
        pHashTable[*(pHashKey++)]++;
    pHashKey = pHead;
    while(*pHashKey != '\0'){
        if(pHashTable[*(pHashKey)] == 1)
            return *pHashKey;
        pHashKey++;
    }
    return '\0';
}
int main(){
    char a[] = "aaefegnrevdfgenllsseewewer";
    int hashTable[256]={0};
    hashTable['a'] = 100;
    cout<<hashTable[97];
    //cout<<findChar(a);
}
