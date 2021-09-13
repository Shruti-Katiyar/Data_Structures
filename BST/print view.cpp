//print view
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

//////////////////view//////////////

void rightview (node*root,int level,int &max_level){
	//base 
	if(!root){
		return;
	}
	//recursive
	if(level>max_level){
		cout<<root->data<<endl;
		max_level=level;
	}
	rightview(root->right,level+1,max_level);
	rightview(root->left,level+1,max_level);
}

int main(){
	node* root = BuildTree();
	PrintLevel(root);
	cout<<endl;
	
	int max_level=0;
	rightview(root,1,max_level);
	
	return 0;
}
//8 3 10 1 6 14 4 7 13 9 -1
