//reandom tree is given check bst

#include <iostream>
#include <queue>
//#include <cmath>
using namespace std;

class node {
public:
	int data;
	node* left;
	node* right;
	node(int d): data(d), left(NULL), right(NULL) {}
};

/////////////////////////////// Create BST //////////////////////////
node* InsertInBST(node* root, int data) {
	// base case
	if (root == NULL) {
		root = new node(data);
		return root;
	}

	// recursive case
	if (data <= root->data) {
		root->left = InsertInBST(root->left, data);
	}
	else {
		root->right = InsertInBST(root->right, data);
	}

	return root;
}

node* BuildTree() {
	node* root = NULL;
	int data;
	cin >> data;

	while (data != -1) {
		root = InsertInBST(root, data);
		cin >> data;
	}

	return root;
}


/////////////check bst////////////////

bool isBST(node* root,int min=INT_MIN,int max=INT_MAX){
	//base 
	if(root==NULL){
		return true;
	}
	//recursive 
	if(root->data>=min and root->data<=max and isBST(root->left,min ,root->data) and isBST(root->right,root->data,max)){
		return true;
	}
	else{
		return false;
	}
	}
	
	int main(){
			node* root = BuildTree();
		   

		    
		    if(isBST(root)){
		    	cout<<"Yes a BST "<<endl;
			}
			else{
				cout<<"No a BST "<<endl;
			}
				
		return 0;
	}
	//8 3 10 1 6 14 4 7 13 9 -1
		
		
		
		
		
		
		
		
		
		
		
	
	
	
	
	
	
	
	
	
	
	

