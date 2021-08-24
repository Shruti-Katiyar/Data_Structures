#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node*next;
		node(int d): data(d),next(NULL){
		}
};
void insert_at_end(node* &head,node* &tail,int data){
	node*n =new node(data);
	if(head==NULL){
		head=tail=n;
	}
	else{
		tail->next=n;
		tail=n;
	}
}

void printll(node*head){
	while(head){
		cout<<head->data<<"-->";
		head=head->next;
	}
	cout<<"NULL"<<endl;
}
//////////////reverse
void reversell(node*&head){
	node*c=head,*prev=NULL,*n;
	while(c){
		n=c->next;
		c->next=prev;
		prev=c;
		c=n;
	}
	head=prev;
}
int main(){
		
		node*head=NULL,*tail=NULL;
		
		insert_at_end(head,tail,10);
		insert_at_end(head,tail,20);
		insert_at_end(head,tail,30);
		insert_at_end(head,tail,40);
		
		printll(head);
		reversell(head);
		printll(head);
		
		cout<<endl;
		return 0;
		
		
	}
