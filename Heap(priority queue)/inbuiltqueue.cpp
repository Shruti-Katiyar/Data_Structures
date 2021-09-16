#include<iostream>
#include<queue>
using namespace std;

int main(){
	priority_queue<int>h;
	h.push(1);
	h.push(4);
	h.push(6);
	h.push(8);
	h.push(10);
	
	while(!h.empty()){
		cout<<h.top()<<endl;
		h.top();
	}
	return 0;
}
