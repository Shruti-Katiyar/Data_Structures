#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
//syntax= unordered_map<key,value>.h
unordered_map<string,int >h;

//1 way to insert
/*h["apple"]=100;
h["pinapple"]=100;
h["mango"]=100;*/

//another way in which user give values 
string key;
int value;
int n;
cin>>n;

for(int i =0; i<n; i++){
    cin>>key>>value;
    h.insert({key,value});
}
// 2nd way
pair<string, int>p("Guava",120);
h.insert(p);
//3rd way
h.insert(make_pair("Banana",40));
// 4th way
h.insert({"Orange",60});

//1 way to print

for(pair<string, int>fruit :h){
    cout<<fruit.first <<"->"<<fruit.second<<endl;
}
cout<<endl;
// 2nd way
for(auto fruit:h){
cout<< fruit.first<<"->" <<fruit.second <<endl;
}
cout <<endl;
//3rd  way
for(auto it=h.begin(); it != h.end(); it++){
    cout<< it->first<<":"<< it->second<<endl;
}
cout<<endl;

//for delete
//h.erase("Orange");
//h.erase("Banana");

//4th way
for(int i  =0; i<h.bucket_count(); i++){
    cout<<i<<"-->";
    for(auto it = h.begin(i); it != h.end(i); it++){
        cout<<"("<<it->first << " "<<it->second <<")";
    }
    cout<<endl;
}
cout<<h["Mango"]<<endl;  // to see value of mango

return 0;
}
