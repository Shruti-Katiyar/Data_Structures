#include<iostream>
using namespace std;
class node{
public:
     int data;
	 node*left;
	 node*right;
	 node(int d): data(d),left(NULL),right(NULL){
	 }	
};
node*Buildtree(){
	int data;
	cin>>data;
	if(data==-1){
		return NULL;
	}
	else{
		node*root=new node(data);
		root->left=Buildtree();
		root->right= Buildtree();
		return root;
	}
}
void preorder(node*root){
	//base case
	if(root==NULL){
		return;
	}
	//recursive case
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

void inorder(node*root){
	//base 
	if(root==NULL){
		return;
	}
	//recursive
	//1.print left
	inorder(root->left);
	//2.root
	cout<<root->data<<" ";
	//3.right
	inorder(root->right);
}

/////////////MIRROR//////////////////////
void mirror(node*root){
	//base case
	if(!root){
		return ;
	}
	//recuersive
	swap(root->left,root->right);
	mirror(root->left);
	mirror(root->right);
	}
int main(){
	node*root=Buildtree();
	mirror(root);
	
	preorder(root);
	cout<<endl;
	inorder(root);
	cout<<endl;

	return 0;
}
//8 3 1 -1 -1 6 4 -1 -1 7 -1 -1 10 -1 14 13 -1 -1 -1
