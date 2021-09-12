//deletion in bst
#include<iostream>
#include<queue>
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
void PrintLevel(node* root) {
	queue<node*> q;
	q.push(root);
	q.push(NULL);

	while (!q.empty()) {
		node* x = q.front(); // x can be an valid address or NULL
		q.pop();
		if ( x == NULL) {
			cout << endl;
			if (!q.empty()) {
				q.push(NULL);
			}
		}
		else {
			cout << x->data << " ";
			if (x->left) {
				q.push(x->left);
			}
			if (x->right) {
				q.push(x->right);
			}
		}
	}
}


//////////////////delete //////////////////////
node* DeleteinBST(node*root,int key){
	//base
	
	//recursive
	if(root->data>key){
		root->left=DeleteinBST(root->left,key);
		return root;
	}
	else if(root->data < key){
		root->right=DeleteinBST(root->right,key);
		return root;
	}
	else{
		// case 1: no child
		if(!root->left and !root->right){
			delete root;
			return NULL;
		}
		// case 2:  1 child that is present in left 
		else if(root->left and !root->right){
			node*temp=root->left;
			delete root;
			return temp;
			
		}
		// 1child is presnt in right
		else if(!root->left and root->right){
			node*temp=root->right;
			delete root;
			return temp;
	}
	//case 3: child are presnt
	node*replace=root->right;
	while(replace->left){
		replace =replace->left;
	}
	swap(root->data,replace->data);
	root->right=DeleteinBST(root->right,replace->data);
	return root;
}
}
int main(){
	
	node* root = BuildTree();
	PrintLevel(root);
	
	cout<<endl;
	
	DeleteinBST(root,9);
    PrintLevel(root);
	
	return 0;
}
//8 3 10 1 6 14 4 7 13 9 -1

