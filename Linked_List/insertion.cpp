#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node*next;
		node(int d): data(d),next(NULL){
		}
};
void insert_at_front(node* &head,node* &tail,int data){
	node*n=new node(data);
	if(head==NULL){
		head=tail=n;
	}
	else{
		n->next=head;
		head=n;
	}
}

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

void insert_at_mid(node* &head,node* &tail,int data,int pos){
	if(pos==0){
		insert_at_front(head,tail,data);
	}
	
else{
	node*temp=head;
	node*n=new node(data);
	for(int i=1;i<=pos-1;i++){
		temp=temp->next;
	}
	n->next=temp->next;
	temp->next=n;
}
}

void printll(node* head){
	while(head){
		cout<<head->data<<"-->";
		head=head->next;
	}
	cout<<"NULL"<<endl;
}

	int main(){
		
		node*head=NULL,*tail=NULL;
		
		insert_at_front(head,tail,1);
		insert_at_front(head,tail,2);
		insert_at_front(head,tail,3);
				
		insert_at_end(head,tail,4);
		insert_at_end(head,tail,5);
		
		printll(head);
				
		insert_at_mid(head,tail,6,3);
				
		printll(head);
		
		cout<<endl;
		return 0;
		
		
	}
