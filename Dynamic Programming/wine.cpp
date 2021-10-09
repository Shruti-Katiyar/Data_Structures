#include<iostream>
#include<string.h>
using namespace std;
int solve (int l,int r,int*price, int day){
	//base case
	if(l>r){
		return 0;
	}
	//recursive case
	int op1=day*price[l]+solve(l+1, r, price, day+1);
	int op2=day*price[r]+solve(l, r-1, price, day+1);
	return max(op1,op2);
}

///////////////////////////////topdown/////////////////////////////

int topdown (int l,int r,int*price, int day,int dp[][100]){
	//base case
	if(l>r){
		return dp[l][r]=0;
	}
	//check
	if(dp[l][r]!=-1){
	    return dp[l][r];
	}
	//recursive case
	int op1=day*price[l]+topdown(l+1, r, price, day+1,dp);
	int op2=day*price[r]+topdown(l, r-1, price, day+1,dp);
	return dp[l][r]= max(op1,op2);
}

/////////////////bottom_up//////////////
int bottomUp(int *price, int n) {
	int dp[100][100] = {0};
	// Iterate on the diagonal to fill the values
	// for selling single bottles
	for (int i = 0 ; i < n ; i++) {
		dp[i][i] = n * price[i];
	}

	for (int i = n - 2 ; i >= 0 ; i--) {
		for (int j = 0 ; j < n ; j++) {
			if (i < j) {
				int day = n - (j - i);
				int op1 = day * price[i] + dp[i + 1][j];
				int op2 = day * price[j] + dp[i][j - 1];

				dp[i][j] = max(op1, op2);
			}
		}
	}

	for (int i = 0 ; i < n ; i++) {
		for (int j = 0 ; j < n ; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	return dp[0][n - 1];
}



int main(){
	int price[] = {2,5,3,1,4};
	int n = sizeof (price) /sizeof(int);
	
	int dp[100][100]={0};
	memset(dp,-1,sizeof(dp));
	
	
	cout<<topdown(0,n-1,price,1,dp)<<endl<<endl;
	cout<<bottomUp(price,n)<<endl<<endl;
	cout<<solve(0,n-1,price,1)<<endl;
	return 0; 
}
