#include<iostream>
#include<list>
#include<queue>
using namespace std;

class graph{
	list<int> *l;
	int V;
public:
	graph(int v){
		V=v;
		l=new list<int>[V];
	}
	void addedge(int i,int j,bool undir=true){
		l[i].push_back(j);
		if(undir){
			l[j].push_back(i);
		}
	}
	void bfs(int source,int dest=-1){
		queue<int> q;
		bool *visited=new bool[V]{0};
		int *dist=new int[V]{0};
		int *parent=new int[V];
		
		for(int i=0;i<V;i++){
			parent[i]=-1;
			
		}
		
		q.push(source);
		visited[source]=true;
		parent[source]=source;
		dist[source]=0;
		
		while(!q.empty()){
			int f=q.front();
			//cout<<f<<endl;
			q.pop();
			
			for(auto nbr:l[f]){
				if(!visited[nbr]){
					q.push(nbr);
					//parent and dist
					parent[nbr]=f;
					dist[nbr]=dist[f]+1;
					visited[nbr]=true;
				}
			}
		}
		
		//print shortest distance
		for(int i=0;i<V;i++){
			cout<<"shortest dist to "<<i<<" is "<<dist[i]<<endl;
		}
		
		//print path 
		if(dest!=-1){
			int temp=dest;
			while(temp!=source){
				cout<<temp<<"--";
				temp=parent[temp];
			}
			cout<<source<<endl;
			
		}
	}
		
};
int main(){
	graph g(7);
	g.addedge(0,1);
	g.addedge(1,2);
	g.addedge(2,3);
	g.addedge(3,5);
	g.addedge(5,6);
	g.addedge(4,5);
	g.addedge(0,4);
	g.addedge(3,4);
	
	g.bfs(1,6);
	
	return 0;
}


