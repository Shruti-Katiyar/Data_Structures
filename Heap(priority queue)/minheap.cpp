#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

class Minheap{
	private:
		void heapify(int i){
			int min_index=i;
			int left=2*i;
			int right=left+1; //2*i+1;
			if(left<v.size()and v[min_index]>v[left]){
				min_index=left;
			}
			if(right<v.size()and v[min_index]>v[right]){
				min_index=right;
			}
			if(min_index!=i){
				swap(v[min_index],v[i]);
				heapify(min_index);
			}
			
		}
		public:
			vector<int>v;
			Minheap(){
			v.push_back(-1); //done b/w we want to avoid 0 index
			}
			
			void push(int data){
				v.push_back(data);
				int c =v.size()-1;
				int p =c/2;
				while(c>1 and v[p]>v[c]){
					swap(v[p],v[c]);
					c=p;
					p/=2;
				}
			}
				
				
				int top(){
					return v[1];
				}
				
				
				void pop(){
					swap(v[1], v[v.size()-1]);
					v.pop_back();
					heapify(1);
				}
				
				
				bool empty(){
					return v.size()==1;
				}
			
};

int main(){
	Minheap h;
	h.push(1);
	h.push(10);
	h.push(81);
	h.push(190);
	h.push(-11);
	h.push(-81);
	
//	cout<<h.top()<<endl;
//	h.pop();
//	cout<<h.top()<<endl;
	
	while(! h.empty()){
		cout<<h.top()<<endl;
		h.pop();
	}
	
	return 0; 
}



