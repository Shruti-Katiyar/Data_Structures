#include<iostream>
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

////////////////////////////bst to ll//////////////////////////
class linkedlist{
	public:
		node* head;
		node* tail;
		linkedlist(){
			head=tail=NULL;
		}
};
linkedlist BSTtoLL(node*root){
	linkedlist l;
	if(root==NULL){
		return l;
	}
	
	if(root->left==NULL and root->right==NULL){
		l.head=l.tail=root;
	}
	else if(root->left !=NULL and root->left==NULL){
		linkedlist left=BSTtoLL(root->left);
		left.tail->right=root;
		l.head=left.head;
		l.tail=root;
	}
	else if(root->left==NULL and root->right !=NULL){
		linkedlist right=BSTtoLL(root->right);
		root->right=right.head;
		l.head=root;
		l.tail=right.tail;
	}
	else{
		linkedlist left=BSTtoLL(root->left);
		linkedlist right=BSTtoLL(root->right);
		left.tail->right=root;
		root->right=right.head;
		l.head=left.head;
		l.tail=right.tail;
	}
	return l;
}

void printll(node*head){
	while(head !=NULL){
		cout<<head->data<<"-->";
		head=head->right;
	}
	cout<<"NULL"<<endl;
	
}

int main(){
	
	node* root = BuildTree();

	linkedlist l=BSTtoLL(root);
	printll(l.head);
	
	
	return 0;
}
//8 3 10 1 6 14 4 7 13 -1
