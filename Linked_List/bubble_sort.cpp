#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node*next;
		node(int d): data(d),next(NULL){
		}
};

///////////////lenght///////////////////
int lenght(node*head){
	int count=0;
	while(head){
		count++;
		head=head->next;
	}
	return count;
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

void printll(node*head){
	while(head){
		cout<<head->data<<"-->";
		head=head->next;
	}
	cout<<"NULL"<<endl;
}


void bubble_sort(node*&head){
	int len=lenght(head);
	node*c,*prev,*n;
	for(int iter=1;iter<=len-1;iter++){
		c=head; prev=NULL;
		while(c and c->next){
			n=c->next;
			if(c->data >n->data){
				//swapping
				if(prev==NULL){
					//head change
					c->next=n->next;
					n->next=c;
					prev=head=n;
				}
				else{
					//head change nhi hogha
					c->next=n->next;
					n->next=c;
					prev->next=n;
					prev=n;
				}
			}
			else{
				//swapping nh hoghi
				prev=c;
				c=n;
			}
		}
	}
		
}
int main(){
		
		node*head=NULL,*tail=NULL;
		
		insert_at_end(head,tail,10);
		insert_at_end(head,tail,2);
		insert_at_end(head,tail,12);
		insert_at_end(head,tail,35);
		insert_at_end(head,tail,5);
		
		printll(head);

	    bubble_sort(head);
		printll(head);
		
		cout<<endl;
		return 0;
		
		
	}
