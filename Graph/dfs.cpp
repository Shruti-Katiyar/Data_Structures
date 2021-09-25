#include<iostream>
#include<list>
#include<queue>
using namespace std;
class graph{
	int V;
	list<int> *l;
public:
       graph(int v){
       	V=v;
       	l=new list<int>[v];
	   }	
	void addedge(int i,int j,bool bidir=true){
		l[i].push_back(j);
		if(bidir){
			l[j].push_back(i);
		}
	} 
	void dfshelper(int node,bool *visited){
		visited[node]=true;
		cout<<node<<",";
		for(int nbr : l[node]){
			if(!visited[nbr]){
				dfshelper(nbr,visited);
			}
		}
		return ;
		
		
	}  
	void dfs(int source){
		bool *visited=new bool[V]{0};
		dfshelper(source,visited);
		
		
			
}
};
int main(){
	graph g(8);
	g.addedge(0,1);
	g.addedge(1,2);
	g.addedge(2,3);
	g.addedge(3,5);
	g.addedge(5,6);
	g.addedge(4,5);
	g.addedge(0,4);
	g.addedge(3,4);
	g.dfs(1);
	return 0;
}
