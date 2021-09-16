#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
#define Minheap priority_queue<int,vector<int>,greater<int>>

void printheap(Minheap h){
	while(!h.empty()){
		cout<<h.top()<<" ";
		h.top();
		
	}
	cout<<endl;
}
int main(){
	Minheap h;
	int n,count=0;
	int k=3;
	while(1){
		cin>>n;
		if(n==-1){
			printheap(h);
		}
		else{
			if(count<k){
				h.push(n);
				count++;
			}
			else{
				if(h.top()<n){
					h.pop();
					h.push(n);
				}
			}
		}
	}
	return 0;
}
