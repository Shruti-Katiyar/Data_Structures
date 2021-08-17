//insertion at end without Tail
#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node*next;
		node(int d): data(d),next(NULL){
		}
};

void insert_at_end(node*&head,int data){
	node*n=new node(data);
	if(head==NULL){
		head=n;
	}
	else{
		node*temp=head;
		while(temp->next){
			temp=temp->next;
		}
		temp->next=n;
	}
}
void printll(node*head){
	while(head){
		cout<<head->data<<"-->";
		head=head->next;
	}
	cout<<"NULL"<<endl;
}
int main(){
		
		node*head=NULL,*tail=NULL;
		
		insert_at_end(head,10);
		insert_at_end(head,20);
		insert_at_end(head,30);
		insert_at_end(head,40);
		
		printll(head);
		
		cout<<endl;
		return 0;
		
		
	}
