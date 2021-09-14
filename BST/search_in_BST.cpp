#include <iostream>
#include <queue>
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



////////////////search////////////////
node* searchBST(node*root,int key){
	//base
	if(!root){
		return root;
	}
	//recursive
	if(root->data==key){
		return root;
	}
	else if(key<=root->data){
		return searchBST(root->left,key);
	}
	else{
		return searchBST(root->right,key);
	}
}

int main(){
		node* root = BuildTree();
		
		
		node* ans=searchBST(root,3);
		if(ans){
			cout<<"found "<<ans->data<<endl;
		}
		else{
			cout<<"not found "<<endl;
		}
		
		return 0;
	}
	

	
//8 3 10 1 6 9 14 4 7 13 -1
