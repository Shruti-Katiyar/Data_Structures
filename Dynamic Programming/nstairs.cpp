#include<iostream>
#include<string.h>
using namespace std;

/*int nstairs(int n){
	if(n==0){
		return 1;
	}
	if(n<0){
		return 0;
	}
	return nstairs(n-1)+nstairs(n-2)+nstairs(n-3);
}*/
int solve(int n,int k){ //this is for kth steps
	if(n==0){
		return 1;
	}
	if(n<0){
		return 0;
	}
	int ans=0;
	for(int i=1;i<=k;i++){
		ans+=solve(n-i,k);
	}
	return ans;
}
//////////////////topdown//////////////

int topdown(int n,int k,int*dp){
	//base case
	if(n==0){
		return dp[n]=1;//store
	}
	if(n<0){
		return 0;
	}
	//check
	if(dp[n] !=-1){
		return dp[n];
	}
	//recursive case
	int ans=0;
	for(int i=1; i<=k;i++){
		ans+=topdown(n-i,k,dp);
	}
	return dp[n]=ans;
}

////////////////bottom-up/////////////////
int bottomup(int n,int k){
	int dp[10005];
	dp[0]=1;
	
	for(int i=1;i<=n;i++){
		int ans=0;
		for(int j=1;j<=k;j++){
			if(i>=j){
				ans+=dp[i-j];
			}
		}
		dp[i]=ans;
	}
	return dp[n];
}

int nstairOptimised(int n,int k){
	int dp[10005];
	dp[0]= dp[1] =1;
	
	for(int i=2; i<=n; i++){
		if(i-k-1>=0){
			dp[i]=2*dp[i-1]-dp[i-k-1];
		}
		else{
			dp[i]=2*dp[i-1];
		}
	}
	return dp[n];
}


int main(){
	int n,k;
	cin>>n>>k;
	
	int dp[1000];
	memset(dp,-1,sizeof(dp));
	
	cout<<topdown(n,k,dp)<<endl;
	cout<<bottomup(n,k)<<endl;
	cout<<nstairOptimised(n,k)<<endl;
	//cout<<nstairs(n)<<endl;
//	cout<<solve(n,3);
	return 0;
}
		
		
	
