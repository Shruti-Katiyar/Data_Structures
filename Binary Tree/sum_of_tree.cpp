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


int sumof_BT(node*root){
	if(!root){
		return 0;
	}
	return sumof_BT(root->left) + sumof_BT(root->right)+ root->data;
}


int main(){
	node*root=Buildtree();
	
	cout<<"sum of tree : "<<sumof_BT(root)<<endl;
	return 0;
}

//8 3 1 -1 -1 6 4 -1 -1 7 -1 -1 10 -1 14 13 -1 -1 -1
