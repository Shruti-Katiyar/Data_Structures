#include<iostream>
#include<queue>
using namespace std;

class MeraComparator{
	public:
		bool operator()(int a,int b){
			return a>b;
		}
};

int main(){
	priority_queue<int,vector<int>,MeraComparator>h;
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
