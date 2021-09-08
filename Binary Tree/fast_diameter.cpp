//fast diameter & height 
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
class Pair{
	public:
		int height;
		int diameter;
};
Pair fastdiameter(node*root){
	Pair P;
	//base
	if(root==NULL){
		return P;
	}
	//recursive
	Pair left = fastdiameter(root->left);
	Pair right = fastdiameter(root->right);
	P.height=max(left.height,right.height)+1;
	
	int op1=left.height + right.height;
	int op2= left.diameter;
	int op3= right.diameter;
	P.diameter=max(op1,max(op2,op3));
	
	return P;
}

int main(){
	node*root=Buildtree();
	Pair ans=fastdiameter(root);
	cout<<"fastdiameter : "<<ans<<endl;
	cout<<"fastheight : "<<ans.height<<endl;
	
	return 0;
}

// 8 3 1 -1 -1 6 4 -1 -1 7 -1 -1 10 -1 14 13 -1 -1 -1
