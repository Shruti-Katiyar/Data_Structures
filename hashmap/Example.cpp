#include<iostream>
#include<string.h>
#include<unordered_map>
#include<vector>
using namespace std;
int main(){
	unordered_map<string,vector<int> >h;
	h["shruti"].push_back(9999);
	h["shruti"].push_back(1111);
	h["shruti"].push_back(5555);
	h["rashi"].push_back(8889);
	
	for(auto person: h){
		//person.first-->key
		//person.second-->value,vector
		cout<<person.first<<"-->";
		for(int i=0; i<person.second.size(); i++){
			cout<<person.second[i]<<" ,";
		}
		cout<<endl;
		
	}
	return 0;
}

