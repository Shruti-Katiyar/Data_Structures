#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
class node{
public:
	char data;
	unordered_map<char,node*> m;
	bool isterminal;

	
	node(char d){
		data=d;
		isterminal=false;
	}
};
class trie{
	node*root;
public:
	trie(){
		root=new node(NULL);
	}
	//insertion
	void insert(string word){
		node* temp=root;
		for(char ch:word){
			if(temp->m.count(ch)==0){
				node* n=new node(ch);
				temp->m[ch]=n;
			}
			temp=temp->m[ch];			
		}
		temp->isterminal=true;
	}
		
	//searching
	bool search(string word){
		node* temp=root;
		for(char ch:word){
			if(temp->m.count(ch)==0){
				return false;
			}
			temp=temp->m[ch];
		}
		return temp->isterminal;
	}
};
int main(){
	string words[]={"hello","he","apple","news"};
	trie t;
	for(auto word:words){
		t.insert(word);
		
	}
	string key;
	cin>>key;
	cout<<t.search(key)<<endl;
	return 0;
	
}
		
		
		
		
		
		
		
	
