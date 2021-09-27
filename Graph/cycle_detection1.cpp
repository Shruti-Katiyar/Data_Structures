//Cycle Detection : Undirected Graph
#include<iostream>
#include<list>
#include<vector>
using namespace std;

class graph{
	list<int> *l;
	int v;
public:
    graph(int v){
    	this->v=v;
    	l=new list<int>[v];
	}
	
	//undirected graph
	void addedge(int x,int y){
		l[x].push_back(y);
		l[y].push_back(x);
	}
	
	bool dfs(int node,vector<bool> &visited,int parent){
		//mark node visited
		visited[node]=true;
		
		for(auto nbr:l[node]){
			
			if(!visited[nbr]){
			  bool nbr_found_cycle = dfs(nbr,visited,node);
			  if(nbr_found_cycle){
			  	return true;
			  }
		   }
		   //nbr is visited & its not the parent of current node in the current dfs path
		    else if(nbr!=parent){
			  	return true;
			  }
			}
			return false;
		}
		
	    bool contains_cycle(){
		    vector<bool> visited(v,false);
		    return dfs(0,visited,-1);
		}	
};
int main(){
	graph g(3);
	g.addedge(0,1);
	g.addedge(1,2);
	g.addedge(2,0);

	cout<<g.contains_cycle()<<endl;
	return 0;
}

