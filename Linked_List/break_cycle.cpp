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
	
	}
	return false;
}


void createcycle(node*head){
	node*temp=head;
	while(temp->next){
	temp=temp->next;
}
  temp->next=head->next->next;
}

void breakcycle(node*head){
	node*fast=head,*slow=head;
	
	while(fast and fast->next){
	fast=fast->next->next;
		slow=slow->next;
		if(fast==slow){
			break;
		}
}
slow= head;
node*prev=head;
while(prev->next!=fast){
	prev=prev->next;
}
while(fast!=slow){
	prev=fast;
	fast=fast->next;
	slow=slow->next;
}
prev->next=NULL;
}


int main(){
		
		node*head=NULL, *tail=NULL;
		
		insert_at_end(head,tail,1);
		insert_at_end(head,tail,2);
		insert_at_end(head,tail,3);
		insert_at_end(head,tail,4);
		insert_at_end(head,tail,5);
		insert_at_end(head,tail,6);
		insert_at_end(head,tail,7);	
		insert_at_end(head,tail,8);
		
		
	
		createcycle(head);
	//	printll(head); agra cycle h or print kroghy to infinite loop chaljayegha
		
		if(iscyclic(head)){
			cout<<"yes cyclic "<<endl;
			breakcycle(head); //cyclic tha or break krdi cycle data loos nh hua
		}
		else{
			cout<<"not cyclic "<<endl;
		}
		printll(head);
		
		return 0;
	}
