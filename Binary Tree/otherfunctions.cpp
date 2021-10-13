#include<iostream>
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

///////////////////////////////count nodes/////////////////////////////////

    int countnodes(node*root){
    //base
    if(root==NULL){
    	return 0;
	}
	//recursive
	return countnodes(root->left) + countnodes(root->right)+ 1;
}

//////////////////////////////////height////////////////////////////////

int height(node*root){
	//base
	if(root==NULL){
		return 0;
	}
	//recursive 
	int left_height=height(root->left);
	int right_height= height(root->right);
	return max(left_height,right_height)+1;
}

/////////////////////////////////diameter///////////////////////////////

int diameter(node*root){
	//base
	if(root==NULL){
		return 0;
	}
	//recursive
	
	//1. diameter in leftsubtree
	int op1=diameter(root->left);
	//2. diam in right
	int op2=diameter(root->right);
	//3. diam rootnode
	int op3=height(root->left) +height(root->right);
	return max(op1, max(op2,op3));
	
}


 int main(){
 	node*root=Buildtree();
 	cout<<"total node : "<<countnodes(root)<<endl;
 	
 	cout<<"Height : "<<height(root)<<endl;
 	
 	cout<<"Diameter : "<<diameter(root)<<endl;
 	
 	return 0;
 }	
 
//input
// 8 3 1 -1 -1 6 4 -1 -1 7 -1 -1 10 -1 14 13 -1 -1 -1
 
