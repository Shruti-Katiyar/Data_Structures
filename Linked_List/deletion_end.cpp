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

void delete_at_end(node* &head,node* &tail){
	if(head==NULL){
		return;
	}
	else if(head->next==NULL){
		delete head;
		head=tail=NULL;
	}
	else{
		node*temp=head;
		while(temp->next!=tail){
			temp=temp->next;
		}
		delete tail;
		tail=temp;
		tail->next=NULL;
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
		
		insert_at_front(head,tail,1);
		insert_at_front(head,tail,2);
		insert_at_front(head,tail,3);
		insert_at_front(head,tail,4);
		
		printll(head);
		
	delete_at_end(head,tail);
	delete_at_end(head,tail);
	printll(head);
		
		cout<<endl;
		return 0;
		
		
	}
