#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

set<string> seperateString(string locationString){
    set<string> locations;
    string delimiter = " ";
    size_t pos = 0;
    string token;
    while ((pos = locationString.find(delimiter)) != std::string::npos) {
        token = locationString.substr(0, pos);
        locations.insert(token);
        locationString.erase(0, pos + delimiter.length());
    }
    return locations;
}


int main() {
    string name;
    map<string,set<string>> map1;
    ifstream ifstream1{"../peoplePlaces.txt"};
while(ifstream1>>name){
    string locationStirng;
    getline(ifstream1,locationStirng);

    map1.insert(pair<string,set<string>>(name,seperateString(locationStirng)));


}

cout<<"name in order:\n";
for_each(begin(map1),end(map1),[](pair<string,set<string>>a){cout<<a.first<<endl;});//print name in order

cout<<"List the people who visited both Krusty-Burger and Tavern:"<<endl;
for_each(begin(map1),end(map1),[](pair<string,set<string>>a){
    if(a.second.find("Krusty-Burger")!=a.second.end()&&a.second.find("Tavern")!=a.second.end())
        cout<<a.first<<endl;
});
cout<<"List the people who did NOT visit Krusty-Burger and Home"<<endl;
for_each(begin(map1),end(map1),[](pair<string,set<string>>a){
    if(a.second.find("Krusty-Burger")==a.second.end()&&a.second.find("Tavern")==a.second.end())
         cout<<a.first<<endl;
    });
cout<<"List the people who visited Krusty-Burger and School but did NOT visit Tavern and Home";
for_each(begin(map1),end(map1),[](pair<string,set<string>>a){
    if(a.second.find("Krusty-Burger")!=a.second.end()&&a.second.find("Tavern")==a.second.end()
                                                       &&a.second.find("Home")==a.second.end())
        cout<<a.first<<endl;
});

cout<<"List the people who visited all locations and remove them from your list";
for_each(begin(map1),end(map1),[&map1](pair<string,set<string>>a){
    if(a.second.find("Krusty-Burger")!=a.second.end()
    &&a.second.find("Tavern")!=a.second.end()
    &&a.second.find("School")!=a.second.end()
    &&a.second.find("Home")!=a.second.end()){
        cout<<a.first<<endl;
        map1.erase(a.first);
    }
});
cout<<"Print out a sorted list of all the people after removal"<<endl;
for_each(begin(map1),end(map1),[](pair<string,set<string>>a){cout<<a.first<<endl;});//print name in order

    return 0;
}
