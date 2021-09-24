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
	void bfs(int source){
		queue<int> q;
		bool *visited=new bool[V]{0};
		
		q.push(source);
		visited[source]=true;
		
		while(!q.empty()){
			int f=q.front();
			cout<<f<<endl;
			q.pop();
			
			for(auto nbr:l[f]){
				if(!visited[nbr]){
					q.push(nbr);
					visited[nbr]=true;
				}
			}
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
	
	g.bfs(1);
	
	return 0;
}
