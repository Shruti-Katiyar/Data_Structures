#include<iostream>
#include<stack>
using namespace std;

int main(){
	//stack<int>s;
	stack<char>s;
	/*s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);*/
	
	s.push('A');
	s.push('B');
	s.push('C');

	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
		
	}
	cout<<endl;
	return 0;
	}
	
