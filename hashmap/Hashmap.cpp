#include<iostream>
#include<string.h>
using namespace std;
	
class node{
		public:
		    int val;
			node* next;
			string key;
			node(string k,int v){
				key=k;
				val=v;
				next=NULL;
			}
				
	};


class hashmap{
		int ts;
		node**arr;
		int cs;//current size
		
		void rehashing(){
			node**oldarr=arr;
			int oldts=ts;
		// 1 double the size of the hashtable	
			arr=new node*[2*ts];
			ts=2*ts;
			cs=0;
			for(int i=0;i<ts;i++){
			arr[i]= NULL;
		}
		// 2 now copy oldtable key values into new hashtable
		for(int i=0; i<oldts; i++){
		   node*head=oldarr[i];
		while(head){
			insert(head->key,head->val);
			head=head->next;
			
		}
	}
	//now we have copied the data
	delete[]oldarr;
} 

int hashfunction(string key){
	int mul=1;
	int ans=0;
	
	for(int i=0;i<key.length();i++) {
	
	   ans+=( (key[i]%ts)*(mul%ts))%ts;
	   mul*=29;
	   mul%=ts;
    }
       ans %= ts;
       return ans;
   }

	public:
			hashmap(int size=7){
			 arr=new node*[size];
			 cs=0;
			 ts=size;
			 //because aaray is of pointers thats why add nullto every bucket
			 for(int i=0;i<ts;i++){		 
			 arr[i]= NULL;
		}
	}
	

	void insert(string key,int val){
	    int index=hashfunction(key);//this will give hash index
	    node*n=new node(key,val);
	    cs++;
	    n->next=arr[index];
	    arr[index]=n;
	    if(cs/(ts*1.0)>0.6){
		  rehashing();
     	}
     }
     
     void print(){
     	for(int i=0;i<ts;i++){
     		cout<<i<<"-->";
     		node*head=arr[i];
     		while(head){
     			cout<<" "<<head->key<<" ";
     			head=head->next;
			 }
			 cout<<endl;
		 }
	}
	 
 };
	 
	 int main() {
	hashmap h;
	h.insert("mango",100);
	h.insert("pinapple",50);
	h.insert("apple",120);
	h.insert("guava",60);

	h.print();
	cout<<endl;
	
	return 0;
 }
     
