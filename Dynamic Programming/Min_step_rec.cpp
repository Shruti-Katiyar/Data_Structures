#include<iostream>

using namespace std;
int minsteps(int n){
	//base
	if(n==1){
		return 0;
	}
	//rec
	int op1,op2,op3;
	op1=op2=op3=INT_MAX;
	 op1=minsteps(n-1);
	 if(n%3==0){
	 	op2=minsteps(n/3);
	 }
	 if(n%2==0){
	 	op3=minsteps(n/2);
	 }
	 return min(op1,min(op2,op3))+1;
}
int main(){
	int n;
	cin>>n;
	cout<<minsteps(n);
	return 0;
}
