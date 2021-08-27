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

/////////////////searching Recursively/////////////////////

node*searchRec(node*head,int key){

//base case
if(!head){
	return NULL;
}
//recursive
if(head->data==key){
	return head;
}
return searchRec(head->next,key);
}

//////////////////serach by iterartive///////////////////////

node*searchIterative(node* head,int key){
	while(head){
		if(head->data==key){
			return head;
		}
		head=head->next;
	}
	return NULL;
}

int main(){
		
		node*head=NULL,*tail=NULL;
		
		insert_at_end(head,tail,1);
		insert_at_end(head,tail,2);
		insert_at_end(head,tail,3);
		insert_at_end(head,tail,4);
		
		printll(head);
		
		///for recurisve
		node*ans=searchRec(head,3);
		if(ans!=NULL){
			cout<<"Node found "<<ans->data<<endl;
		}
		else{
			cout<<"Not found "<<endl;
		}
		
		///for iterative
		ans=searchIterative(head,3);
		if(ans!=NULL){
			cout<<"Node found "<<ans->data<<endl;
		}
		else{
			cout<<"Not found "<<endl;
		}
		
		
		cout<<endl;
		return 0;
		
		
	}
