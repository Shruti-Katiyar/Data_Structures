#include<iostream>
using namespace std;
/*(class node{
	public:
		int data;
		node*next;
		node(int d){
			data=d;
			next=NULL;
		}
};*/
class queue{
	int*arr;
	int f,e,n,cs;
public:
	queue(int s=5){
		arr=new int [s];
		n=s;
		f=0;
		e=n-1;
		cs=0;
	}
	void push(int d){
		if(cs<n){
			e=(e+1)%n;
			arr[e]=d;
			cs++;
		}
		else{
			cout<<"queue overflow"<<endl;
		}
	}
	void pop(){
		if(cs>0){
			f=(f+1)%n;
			cs--;
		}
		else{
			cout<<"queue underflow"<<endl;
		}
	}
	
	int front(){
		return arr[f];
	}
	
	bool empty(){
		return cs==0;
	}
	
	int size(){
		return cs;
	}
};

int main(){
     queue q;
	
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
}
cout<<endl;

return 0;
}
