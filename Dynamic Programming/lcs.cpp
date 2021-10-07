#include<iostream>
#include<string.h>
using namespace std;

char s1[100], s2[100];
int lcs(int i,int j){
	////base case
	if(s1[i]== '\0' || s2[j]== '\0'){
		return 0;
	}
	//recursive case
	if(s1[i] == s2[j]) {
		return 1+ lcs(i+1, j+1);
	}
	else{
		return max(lcs(i+1,j) , lcs(i,j+1));
	}
}
////////////////topdown/////////////incomplete

int topdown(int i,int j,int dp[100][100]){
	//base
	if(s1[i]=='\0'|| s2[j]=='\0'){
		return dp[i][j]=0;
	}
	//check
	if(dp[i][j]!=-1){
		return dp[i][j];
	}
	//rec
	if(s1[i]==s2[j]){
		return dp[i][j]=1+topdown(i+1,j+1,dp);
	}
	else{
		return dp[i][j]= max(topdown(i+1,j,dp),topdown(i,j+1,dp));
	}
}

/////////////////////////////bottom-up///////////////////
int bottomup()
{
   int dp[100][100]={0};
   int n=strlen(s1);
   int m=strlen(s2);
   
   for(int i=1;i<=n;i++){
   	for(int j=1;j<=m;j++){
   		if(s1[i-1]==s2[j-1]){
   			dp[i][j]=1+dp[i-1][j-1];
		   }
		   else{
		   	dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		   }
	   }
   }
   return dp[n][m];

	
}

int main(){
	cin>>s1>>s2;

    int dp[100][100];
	memset(dp,-1,sizeof(dp));

	cout<<topdown(0, 0,dp)<<endl;
	cout<<bottomup()<<endl;
	
	cout<<lcs(0,0)<<endl;
			
	return 0;
}

