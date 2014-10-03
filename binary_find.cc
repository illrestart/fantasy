#include <iostream>
using namespace std;
int binary_find(int data[],int len,int x){
	int left,right,mid;
	cout<<len<<x;
	left = 0;
	right = len-1;
	while(left <= right){
		mid = left + (right - left) /2;
		cout<<mid<<endl;
		if(data[mid] == x){
			return mid;
		}
		else if(data[mid] < x){
			left = mid + 1;
		}
		else if(data[mid] > x){
			right = mid -1;
		}
	}
	return right;
}
int main(){
	int data[] = {1,4,6,6,6,6,6,10,10,10,10,10,10,10,23,56,79,100,100,100,100,100,100,100,100,100,235};

	int left = binary_find(data,sizeof(data)/4,100-1);
	int right = binary_find(data,sizeof(data)/4,100+1);
	cout<<right -left;
	return 0;

}
