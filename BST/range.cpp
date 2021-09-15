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


///////////print range/////////////////////////////////
void Printrange(node* root,int k1,int k2){
	//base
	if(!root){
		return ;
	}
	//recursive
	Printrange(root->left, k1, k2);
		if(root->data >=k1 and root->data<=k2){
			cout<<root->data<<" ";
			
		}
		Printrange(root->right,k1,k2);
	}


int main(){
		node* root = BuildTree();
	
		
		Printrange(root,7,13);
		
		return 0;
	}
	
//8 3 10 1 6  14 4 7 13 -1
