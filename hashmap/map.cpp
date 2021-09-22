#include<iostream>
#include<map>
using namespace std;

int main(){
	map<string,int> h;
	string key;
	int value;
	int n;
	cin>>n;
	
	for(int i=0; i<n; i++){
		cin>>key>>value;
		h.insert({key,value});
	}
	
	// 2 way
	pair<string, int>p("gauva",120);
	h.insert(p);

// 3 way
h.insert(make_pair("banana",40));

// 4 way
h.insert({"orange",60});

//for print
for(auto fruit:h){
	cout<<fruit.first<<"-->"<<fruit.second<<endl;
	
}
cout<<endl;
return 0;
}
