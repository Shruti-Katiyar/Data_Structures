#include<iostream>
#include<string.h>
using namespace std;

int topdown(int i,int j,int cost[][4],int dp[][100]){
//base case
if(i==0 and j==0){
	return dp[i][j] = cost[i][j];//store
}
if(i<0 ||j<0){
	return INT_MAX;
}

if(dp[i][j] != -1){//check
	return dp[i][j];
}
//recursive 
int op1= topdown(i-1,j,cost,dp);
int op2=topdown(i,j-1,cost,dp);
return dp[i][j] = min(op1,op2)+cost[i][j];
}


///////////////////bottomup////////////
int bottomup(int a,int b,int cost[][4]){
	int dp[100][100];
	dp[0][0]=cost[0][0];
	int sum= cost[0][0];
	for(int k=1;k<4;k++){
		sum +=cost[0][k];
		dp[0][k]= sum;
	}
	sum=cost[0][0];
	for(int k=1;k<4;k++){
		sum+=cost[k][0];
		dp[k][0]=sum;
	}
	
	for(int i=1;i<4; i++){
		for(int j=1;j<4;j++){
			dp[i][j]=cost[i][j]+min(dp[i-1][j],dp[i][j-1]);
		}
	}
	return dp[a][b];
}

int main(){
	int cost[][4]={
	{2,1,3,4},
    {3,1,1,10},
    {1,6,1,1},
	{2,7,4,3}
};
int dp [100][100];
memset(dp,-1,sizeof(dp));
int i=2,j=3;

cout<<topdown(i,j,cost,dp)<<endl;
cout<<bottomup(i,j ,cost);
cout<<endl;
return 0;
}

