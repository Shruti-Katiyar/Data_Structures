//merg 2 list using recursion
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



/////////////////MERG///////////////////////
node*merge(node* a,node*b){
	//base
	if(a==NULL){
		return b;
	}
	if(b==NULL){
		return a;
	}
	//recursive
	node* newhead;
	if(a->data<b->data){
		newhead=a;
		node*c=merge(a->next,b);
		newhead->next=c;
	}
	else{
		newhead=b;
		node*c=merge(a,b->next);
		newhead->next=c;
	}
	return newhead;
	
}
int main(){
		
		node*head=NULL, *head1=NULL,*tail=NULL;
		
		insert_at_end(head,tail,1);
		insert_at_end(head,tail,2);
		insert_at_end(head,tail,5);
		insert_at_end(head,tail,7);
		insert_at_end(head,tail,21);
				
		printll(head);
		
		insert_at_end(head1,tail,3);
		insert_at_end(head1,tail,4);
		insert_at_end(head1,tail,6);
		insert_at_end(head1,tail,43);
		insert_at_end(head1,tail,70);
	
	   	printll(head1);
	   	
	   	node* newhead=merge(head, head1);
		printll(newhead);
	    	
		
		cout<<endl;
		return 0;
		
		
	}
