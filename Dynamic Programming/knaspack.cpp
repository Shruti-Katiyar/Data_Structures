#include<iostream>
#include<string.h>
using namespace std;

int knapsack (int*price, int*weight,int capacity,int n,int dp[][100]){
	//base case
	if(capacity==0 or n==0){
		return dp[n][capacity]= 0;//return say phlay store
	}
	
	//calculate say phlay check
	if(dp[capacity][n]!=-1){
		return dp[n][capacity];
	}
	
	
	//recurisve case
	//1.include item
	int op1=INT_MIN ;
	int op2=INT_MIN;
	if(capacity>=weight[n-1]){
		op1=price[n-1]+knapsack(price,weight,capacity-weight[n-1],n-1,dp);
	}
	//2.exclude item
	    op2= 0+knapsack(price,weight,capacity,(n-1),dp);
	    return dp[n][capacity] = max(op1,op2);
}

/////////////////bottom up/////////////////////
int bottomup(int*price,int*weight,int capacity,int N){
	int dp[100][100]={0};
	for(int n=1; n<=N; n++){
		for(int c_cap=1; c_cap<=capacity; c_cap++){
			int op1=INT_MIN, op2 = INT_MIN;
			if(c_cap>=weight[n-1]){
			op1=price[n-1]+dp[n-1][c_cap-weight[n-1]];
		}
		op2=0+dp[n-1][c_cap];
		dp[n][c_cap]=max(op1,op2);
	}
}
//printing
for(int n=0; n<=N; n++){
   for(int c_cap=0; c_cap<=capacity; c_cap++){
   	cout<<dp[n][c_cap]<<" ";
   }
   cout<<endl;
}
 return dp[N][capacity];
}


int main(){
	int price[]={4,5,8,1};
	int weight[]={1,3,5,1};
	int n=sizeof(weight)/sizeof(int);
	
	int dp[100][100];
	memset(dp,-1,sizeof(dp));
	int capacity=5;
	cout<<knapsack(price,weight,capacity,n,dp);
	cout<<endl;
	cout<<bottomup(price,weight,capacity,n);
	
	return 0;
	
}
