#include <iostream>
#include <limits.h>
using namespace std;

class Solution {
public:
    int atoi(const char *str) {
        if(str == NULL) return 0;
        long long result=0;
        int flag = 0;
        int i;
        int len = 0;
        while(*str == ' ') str++;
        if(str[0] == '+'){
            flag = 0;
            str++;
        }else if(str[0] == '-'){
            flag = 1;
            str++;
        }
        while(*str>='0'&&*str<='9'){
            result = result*10 + (*str -'0');
            str++;
        }
        if(result > ((1<<31)-1))return flag?0x80000000:0x7fffffff;
        return !flag?(int)result:(int)(0-result);
    }
};
class Solution1 {
//note:
//1. NULL
//2. sign
//3. prefix ' '
//4. out of range, to avoid this we use long long
public:
    int atoi(const char *str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(str == NULL) return 0;//NULL
        while (*str == ' ')//prefix ' '
            str++;
        int sign = 1;
        if(*str == '-')//sign '+' or '-'
        {
            sign = -1;
            str++;
        }
        else if(*str == '+')
            str++;
        long long ans = 0;
        while (*str >= '0' && *str <= '9')
        {
            ans = ans*10+*str-'0';
            if(ans > INT_MAX)//out of range
                return sign < 0 ? INT_MIN : INT_MAX;
            str++;
        }
        ans *= sign;
        return (int)ans;
    }
};
int main(){
    Solution s;
    Solution1 s1;
    int a=0x80000000;
    cout<<sizeof(bool);
    cout<<a<<endl;
    char* c = "1";
    char* c1 = "2147483648";
    char* c2 = "-2147483648";
    //cout<<sizeof(long long int)<<endl;
    //cout<<(1<<31)-1<<endl;
    cout<<s.atoi(c2)<<endl;
    cout<<s1.atoi(c2)<<endl;

    return 0;
}
