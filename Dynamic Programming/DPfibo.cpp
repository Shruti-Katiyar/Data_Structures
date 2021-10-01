#include<iostream>
using namespace std;

int fibo(int n){
	if (n==0||n==1){
		return n;
	}
	return fibo(n-1)+fibo(n-2);
	 
}

////////////////////////////topdown////////////////////////

int topdown(int n,int*dp){
	//base case
	if(n==0||n==1){
		return dp[n]=n;
	}
	
	//check if function is already calculated?
	if(dp[n]!=-1){
		return dp[n];
	}
	//recursive case
	int ans=topdown(n-1,dp)+topdown(n-2,dp);
	dp[n]=ans; 
	return ans;
	//or
	
//	return dp[n]= topdown(n-1,dp)+topdown(n-2,dp);
}
	
/////////////////////////bottom-up//////////////////////
int bottom_up(int n){
	int *dp=new int[n+1];
	
	//intialize
	dp[0]=0;
	dp[1]=1;
	for(int i=2;i<=n;i++){
		dp[i]=dp[i-1]+dp[i-2];
	}
	cout<<"BOTTOM-UP : ";
	for(int i=0;i<=n;i++){
		cout<<dp[i]<<" ";
	}
	cout<<endl;
	return dp[n];
}

int main(){
	int n;
	cin>>n;
	int *dp=new int[n+1];
	for(int i=0;i<=n;i++){
		dp[i]=-1;
	}
	cout<<topdown(n,dp)<<endl;
	cout<<bottom_up(n)<<endl;
	
	cout<<fibo(n)<<endl;
	return 0;
}
	 
