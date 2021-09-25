#include<iostream>
#include<vector>
#include<set>
#include<climits>
using namespace std;
class node{
	public:
		int x;
		int y;
		int dist;
		
		node(int x,int y,int dist){
			this->x=x;
			this->y=y;
			this->dist=dist;
		}
};
class compare{
	public:
		bool operator()(const node &a,const node &b){
			return a.dist <= b.dist;
		}
};
 
int shortest_path(vector<vector<int> >grid){
	int m=grid.size();
	int n=grid[0].size();
	
	int i=0;
	int j=0;
	
	vector<vector<int> >dist(m+1, vector<int> (n+1,INT_MAX));
	dist[i][j]=grid[i][j];
	
	set<node,compare> s;
	s.insert(node(0,0,dist[0][0]));
	
	int dx[]={0,0,1,-1};
	int dy[]={1,-1,0,0};
	
	while(!s.empty()){
		auto it=s.begin();
		int cx=it->x;
		int cy=it->y;
		int cd=it->dist;
		s.erase(it);
		
		for(int k=0;k<4;k++){
			int nx=cx + dx[k];
			int ny=cy + dy[k];
			
			if(nx>=0 and nx<m and ny>=0 and ny<n and cd +grid[nx][ny] < dist[nx][ny]){
				//remove old node if it exist
				node temp(nx,ny,dist[nx][ny]);
				if(s.find(temp)!=s.end()){
					s.erase(s.find(temp));
				}
				
				//insert new node
				int nd=grid[nx][ny] + cd;
				dist[nx][ny]=nd;
				s.insert(node(nx,ny,nd));
				
			}
		}
	}
	return  dist[m-1][n-1];
}
int main(){
	vector<vector<int> >grid={
	{31,100,65,12,18},
	{10,13,47,157,6},
	{100,113,174,11,33},
	{88,124,41,20,140},
	{99,32,111,41,20},
};
cout<<shortest_path(grid)<<endl;


return 0;
}
	
	

