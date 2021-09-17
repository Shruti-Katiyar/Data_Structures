#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
	priority_queue<int,vector<int>,greater<int>>h;
	h.push(1);
	h.push(10);
	h.push(12);
	h.push(6);
	h.push(5);
	
	while(!h.empty()){
		cout<<h.top()<<endl;
		h.pop();
	}
	return 0;
}
