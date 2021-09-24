#include<iostream>
#include<list>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

class graph{
	int V;
	list<int> *l;
public:
   graph(int V){
    this->V=V;
   	l=new list<int>[V];
   }
   
    void addedge(int i,int j){
        l[i].push_back(j);
    }

   void topological_sort(){
   	    vector<int> indegree(V,0);
   	    for(int i=0;i<V;i++){
   		    for(auto nbr:l[i]){
		 	indegree[nbr]++;
		}
	}
	   
   
   //bfs
   queue<int> q;
   for(int i=0;i<V;i++){
   	    if(indegree[i]==0){
   		    q.push(i);
	   }
   }
   
    while(!q.empty()){
   	    int node=q.front();
     	cout<<node<<" ";
    	q.pop();
   	
   	    for(auto nbr: l[node]){
   	    	indegree[nbr]--;
   		        if(indegree[nbr]==0){
   			        q.push(nbr);
   			    }
   			}
   		}
   	}
  
 			
};
   
 int main(){
	graph g(6);
	g.addedge(0,2);
	g.addedge(2,3);
	g.addedge(3,5);
	g.addedge(4,5);
	g.addedge(1,4);
	g.addedge(1,2);
	
	g.topological_sort();
	
	return 0;
}
