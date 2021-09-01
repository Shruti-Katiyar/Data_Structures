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

////////// finding mid without calculating length////////////////////

node* mid(node*head){
	if(!head){
		return head;
	}
	node*fast=head->next,*slow=head;
	
	while(fast and fast->next){
		fast=fast->next->next;
		slow=slow->next;
	}
	return slow;
}

int main(){
		
		node*head=NULL,*tail=NULL;
		
		insert_at_end(head,tail,10);
		insert_at_end(head,tail,20);
		insert_at_end(head,tail,30);
		insert_at_end(head,tail,40);
		insert_at_end(head,tail,50);
		insert_at_end(head,tail,60);
		
		printll(head);
		
	
		 node*ans = mid(head);
		if(ans!=NULL){
			cout<<"MIDDLE found "<<ans->data<<endl;
		}
		else{
			cout<<"Not found "<<endl;
		}
		cout<<endl;
		return 0;
		
		
	}
