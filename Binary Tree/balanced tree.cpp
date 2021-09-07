//check tree is balanced
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
//ye tree banya h
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

////////////////////////checking tree is balanced or not////////
class Pair{
	public:
		int height;
		bool balanced;
		Pair(){
			height =0;
			balanced=true;
		}
};
Pair isbalanced(node* root){
	Pair p;
	//base 
	if(root==NULL){
		return p;
	}
	//recursive
	Pair left=isbalanced(root->left);
	Pair right=isbalanced(root->right);
	
	p.height=max(left.height,right.height)+1;
	if(left.balanced and right.balanced and (abs(left.height - right.height)<=1)){
		p.balanced=true;
	}
	else{
		p.balanced=false;
	}
	return p;
}


int main(){
	node* root=BuildTree();
	
	Pair ans=isbalanced(root);
	if(ans.balanced){
		cout<<"Tree is balanced "<<endl;
	}
	else{
		cout<<"Not balanced tree "<<endl;
	}
	cout<<"height "<<ans.height<<endl;

return 0;
}
//8 3 10 1 6 14 4 7 13 -1 : not balanced

//8 3 10 1 6 14 4 7 13 9 -1 : balanced


