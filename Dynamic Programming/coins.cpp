#include<iostream>
#include<string.h>
using namespace std;

int solve(int amount,int*coins,int n){
	//base case
	if(amount==0){
		return 0;
	}
	
	//recursive case
	int ans=INT_MAX;
	for(int i=0;i<n;i++){
		if (amount -coins[i]>=0){
			int chotiamount = amount -coins[i];
			int chotaans =solve(chotiamount,coins,n);
			if(chotaans !=INT_MAX and chotaans<ans){
				ans=chotaans+1;
			}
		}
		
  }

  return ans;
}
////////////////////////////topdown///////////////////////

int topdown(int amount,int*coins,int n,int *dp){
	//base case
	if(amount==0){
		return dp[amount]=0;  //return say phalay store it
	}
	//check
	if(dp[amount] !=-1){
		return dp[amount];
	}
	//recursive case
	int ans=INT_MAX;
	for(int i=0;i<n;i++){
		if (amount -coins[i]>=0){
			int chotiamount = amount -coins[i];
			int chotaans =topdown(chotiamount,coins,n,dp);
			if(chotaans !=INT_MAX and chotaans<ans){
				ans=chotaans+1;
			}
		}
		
  }
//store
  return dp[amount]= ans;
}	

//////////////////////bottom-up////////////////////

int bottomup(int amount,int*coins,int n){
	int*dp=new int[amount +1];
	for(int i=0;i<=amount; i++){
		dp[i]=INT_MAX;
	}
	dp[0]= 0;
	
	for(int rupay =1;rupay<=amount ;rupay++){
		for(int i=0;i<n; i++){
			if(rupay- coins[i]>=0){
				int chtamt = rupay-coins[i];
				dp[rupay]= min(dp[chtamt]+1,dp[rupay]);
			}
		}
	}
	//this for printing dp array
	for(int i=1;i<=amount;i++){
	cout<<dp[i]<<" ";
    }
    cout<<endl; 
    return dp[amount];
}

	
int main(){
	int coins[]={1,3,5,10};
	int n=sizeof(coins)/sizeof(int);
	
	int dp[10000];
	memset(dp,-1,sizeof(dp));
	
	int amount;
	cin>>amount;
	
	cout<<topdown(amount,coins,n,dp)<<endl;
	cout<<bottomup(amount,coins,n)<<endl;
	cout<<solve(amount,coins,n)<<endl;
	
	cout<<endl;
	return 0;
}
