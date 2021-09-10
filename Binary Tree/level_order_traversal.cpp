#include<iostream>
#include<queue>
using namespace std;
class node{
public:
		int data;
		node*left;
		node*right;
		node(int d):data(d),left(NULL),right(NULL) {}
		
};
node* Buildtree(){
	int data;
	cin>>data;
	if(data==-1){
		return NULL;
	}
	else{
		node*root=new node(data);
		root->left=Buildtree();
		root->right=Buildtree();
		return root;
	}
}

void printlevel(node*root){
	queue<node*>q;
	q.push(root);
	q.push(NULL);
while(!q.empty()){
	node*X=q.front();
	q.pop();
	if(X==NULL){
		cout<<endl;
		if(!q.empty()){
			q.push(NULL);
		}
	}
	else{
		cout<<X->data<<" ";
		if(X->left != NULL){
        q.push(X->left);
	}
	if(X->right!=NULL){
		q.push(X->right);
	}
  }
}
}


node*BuildTraversal(){
	node*root=NULL;
	int data;
	cout<<"enter root data : ";
	cin>>data;
	if(data==-1){
		return NULL;
	}
	root=new node(data);
	
	queue<node*>q;
	q.push(root);
	while(!q.empty()){
		node*X=q.front();
		q.pop();
		
	cout<<"enter data of child: "<<X->data<<endl;
	int left_data,right_data;
	cin>>left_data>>right_data;
	if(left_data !=-1){
		X->left=new node(left_data);
		q.push(X->left);
	}	
	if(right_data!=-1){
		X->right=new node(right_data);
		q.push(X->right);
	}
}
return root;
}

int main(){
    node*root=BuildTraversal();
    printlevel(root);
	
	
	return 0;
}
//8 3 1 -1 -1 6 4 -1 -1 7 -1 -1 10 -1 14 13 -1 -1 -1
