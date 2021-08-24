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

void printll(node*head){
	while(head){
		cout<<head->data<<"-->";
		head=head->next;
	}
	cout<<"NULL"<<endl;
}

//////////////length

int lengthRec(node*head){
	//base case
	if(!head){
		return 0;
	}
	//recursive 
	return 1+lengthRec(head->next);
}

	int main(){
		
		node*head=NULL,*tail=NULL;
		
		insert_at_front(head,tail,1);
		insert_at_front(head,tail,2);
		insert_at_front(head,tail,3);
		insert_at_front(head,tail,4);
		
		printll(head);
		cout<<lengthRec(head);
		
		cout<<endl;
		return 0;
		
		
	}
