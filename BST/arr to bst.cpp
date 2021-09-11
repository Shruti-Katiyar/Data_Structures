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


//////////////////array to BST////////////
node*createTree(int *arr,int s,int e){
	//base
	if(s>e){
		return NULL;
	}
	//recursive
	int mid=(s+e)/2;
	node*root=new node(arr[mid]);
	root->left=createTree(arr,s,mid-1);
	root->right=createTree(arr,mid+1,e);
	return root;
}
int main(){
	int arr[]={1,2,3,4,8,9,10};
	int n=sizeof(arr)/sizeof (int);
	node*root=createTree(arr,0,n-1);
	
     PrintLevel(root);
	return 0;
}
