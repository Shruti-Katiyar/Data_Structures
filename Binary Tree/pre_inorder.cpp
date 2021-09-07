// pre,inoreder say tree banaya h or pre,post,in print kiya h..
// kuch bhi print kr sktai h ye as treee kam kregha
#include<iostream>
using namespace std;
class node{
public:
		int data;
		node*left;
		node*right;
		node(int d):data(d),left(NULL),right(NULL) {}
		
};


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

void postorder(node*root){
	//base 
	if(root==NULL){
		return;
	}
		
	//recursive
	
	//1 left
	postorder(root->left);
	//2 right
	postorder(root->right);
	// root
	cout<<root->data<<" ";
}

//////////////////////tree from preorder & inorder
int pre[]={8,3,1,6,4,7,10,14,13};
int i=0;
int in[]={1,3,4,6,7,8,10,13,14};

node* createTree(int s,int e){
	//base case
	if(s>e){
		return NULL;
	}
	
	//recursive
	int d=pre[i++];
	node*root=new node(d);
	int k=-1;
	for(int j=s;j<=e;j++){
		if(in [j]==d){
			k=j;
			break;
		}
	}
	root->left=createTree(s,k-1);
	root->right=createTree(k+1,e);
	
	return root;
}

int main(){
	int n=sizeof(in)/sizeof(int);
	node*root=createTree(0,n-1);
	
	preorder(root);
	cout<<endl;
	
	inorder(root);
	cout<<endl;
	
	postorder(root);
	cout<<endl;

	return 0;
}
