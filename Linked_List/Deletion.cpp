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
//////////////length recursive///////

int length(node*head){
	//base case
	if(!head){
		return 0;
	}
	//recursive 
	return 1+length(head->next);
}

void delete_at_front(node* &head,node* &tail){
	if(head==NULL){
		return;
	}
	else if(head->next==NULL){
		delete head;
		head=tail=NULL;
	}
	else{
		node*n=head;
		head=head->next;
		delete n;
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

void delete_at_mid(node* &head,node* &tail,int pos){
	if(pos==0){
		delete_at_front(head,tail);
	}
	else if(pos>=length(head)-1){
		delete_at_end(head,tail);
	}
	else{
		node*temp=head;
		for(int i=1; i<pos;i++){
			temp=temp->next;
		}
		node*n=temp->next;
		temp->next=n->next;
		delete n;
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
		insert_at_front(head,tail,5);
		insert_at_front(head,tail,6);
		
		printll(head);
		
		//delete_at_front(head,tail);
	    //delete_at_front(head,tail);
	   // printll(head);
	    
	    delete_at_mid(head,tail,2);
	    printll(head);
		
		cout<<endl;
		return 0;
		
		
	}
