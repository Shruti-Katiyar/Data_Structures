#include<iostream>
#include<string.h>
using namespace std;
int elephantways(int i,int j){
	//base case
	if(i==0 and j==0){
		return 1;
	}
	//recursive case
	int ans=0;
	for(int k=0; k<i; k++){
		ans+= elephantways (k,j);
	}
	for(int k=0; k<j; k++){
		ans += elephantways(i,k);
	}
	return ans;
}

///////////////////////////topdown/////////////////////////////
int topdown(int i,int j,int dp[100][100]){
	//base
	if(i==0 and j==0){
		return dp[i][j]=1;
	}
	
	//check
	
	if(dp[i][j]!=-1){
		return dp[i][j];
	}
	
	//rec
	int ans=0;
	for(int k=0;k<i;k++){
		ans+=topdown(k,j,dp);
	}
	for(int k=0;k<j;k++){
		ans+=topdown(i,k,dp);
	}
	return dp[i][j]=ans;
}

///////////////////////bottom-up////////////////////////////

int bottom(int n,int m){
	int dp[100][100]={0};
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(i==0 and j==0){
				dp[i][j]=1;
			}
			else{
				int ans=0;
				for(int k=0;k<i;k++){
					ans+=dp[k][j];
				}
				for(int k=0;k<j;k++){
					ans+=dp[i][k];
				}
				dp[i][j]=ans;
			}
		}
	}
	return dp[n][m];
}

int main(){
	int i,j;
	cin>>i>>j;
	int dp[100][100];
	memset(dp,-1,sizeof(dp));
	cout<<topdown(i,j,dp)<<endl;
	cout<<bottom(i,j)<<endl;
	cout<<elephantways(i,j);
	
	
	cout<<endl;
	
	return 0;
}
