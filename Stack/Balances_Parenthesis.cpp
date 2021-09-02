#include<iostream>
#include<stack>
using namespace std;

bool isbalanced(char* a){
	stack<int>s;
	for(int i=0; a[i]; i++){
		char ch= a[i];
		switch (ch){
			case '(':
			case '{':
			case '[': s.push(ch);
			break;
			
			case ')':
				if(!s.empty() and s.top()=='('){
					s.pop();
				}
				else{
					return false;
				}
			break;
			
			case'}':
				if(!s.empty() and s.top()=='{'){
					s.pop();
				}
				else{
					return false;
				}
				
				break;
				
				case']':
					if(!s.empty() and s.top()=='['){
					s.pop();
				}
				else{
					return false;
				}
			}	
				
		}
		return s.empty();
	}
	
int main(){
	char a[]="[{(a+b)+c(d+e)}]}}}";
	if(isbalanced (a)){
		cout<<"BAlANCED"<<endl;
	}
	else{
		cout<<"NOT BALANCED"<<endl;
	}
	return 0;
}	


