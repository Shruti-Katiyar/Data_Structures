#include<iostream>
using namespace std;

class node{
	public:
		int data;
		node*next;
		node(int d){
			data=d;
			next=NULL;
		}
};
class stack{
private:
		node*head;
		int len;
public:
		stack(){
			head=NULL;
			len=0;
		}
		
void push(int d){
	node* n=new node(d);
	n->next=head;
	head= n;
	len++;
}		

void pop(){
	//delete at front
	if(head==NULL){
		return;
	}
	else if(head->next==NULL)
	delete head;
	head=NULL;
	len--;
}
else {
	node* n=head;
	head=head->next;
	delete n;
	len--;
}

bool empty(){
	return head==NULL; 
	//len==0;
}

int size(){
	return len;
}

int top(){
	return head->data;
}

};

int main(){
	stack s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);
	
	while(!s .empty()){
		cout<<s.top()<<" ";
		s.pop();
	}
	cout<<<endl;
	
	return 0;
}








