//cycle detection
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
////////////////////cycle detection
bool iscyclic(node*head){
	node*fast=head,*slow=head;
	while(fast and fast->next){
		fast=fast->next->next;
		slow=slow->next;
		if(fast==slow){
			return true;
			
		}
		return false;
	}
}
int main(){
		
		node*head=NULL, *tail=NULL;
		
		insert_at_end(head,tail,1);
		insert_at_end(head,tail,2);
		insert_at_end(head,tail,15);
		insert_at_end(head,tail,7);
		insert_at_end(head,tail,4);
				
		printll(head);
		
		if(iscyclic(head)){
			cout<<"yes cyclic "<<endl;
		}
		else{
			cout<<"not cyclic "<<endl;
		}
		
		return 0;
	}
