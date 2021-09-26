#include<iostream>
#include<list>
using namespace std;

class graph{
	int v;
	list<int> *l;
public:
   graph(int n){
   	v=n;
   	l=new list<int>[v];
   }
   
   void addedge(int i,int j,bool undir=true){
    l[i].push_back(j);
    if(undir){
    	l[j].push_back(i);
	}
   }	

void printlist(){
	for(int i=0;i<v;i++){
		cout<<i<<"->";
		
		for(auto node:l[i]){
			cout<<node<<",";
		}
		cout<<endl;
	}
}
};
int main(){
	graph g(6);
	g.addedge(0,1);
	g.addedge(0,4);
	g.addedge(2,1);
	g.addedge(3,4);
	g.addedge(4,5);
	g.addedge(2,3);
	g.addedge(3,5);
	
	g.printlist();
	
	return 0;
}
