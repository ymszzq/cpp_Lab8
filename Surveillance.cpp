//
// Created by gmziv on 2018-11-16.
//

#include <algorithm>
#include "Surveillance.h"
//constructor take in file path and generate map
Surveillance::Surveillance(string filePath) {
    string name;
    filePath = "../"+filePath;
    ifstream ifstream1{filePath};
    while(ifstream1>>name){
        string locationStirng;
        getline(ifstream1,locationStirng);
        map1.insert(pair<string,set<string>>(name,seperateString(locationStirng)));

    }

}


//this function is helper funtion to seperate a string with deliminator space
//@param locationString is the string of locations.
set<string> Surveillance::seperateString(string locationString){
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
//this function will print name in order
void Surveillance::printNameInOrder() {
    cout<<"name in order:\n";
    for_each(begin(map1),end(map1),[](pair<string,set<string>>a){cout<<a.first<<endl;});//print name in order
}
//this function will print person who visit both Krusty-Burger and Tavern
void Surveillance::krustyBurgerAndTavern() {
    cout<<"List the people who visited both Krusty-Burger and Tavern:"<<endl;
    for_each(begin(map1),end(map1),[](pair<string,set<string>>a){
        if(a.second.find("Krusty-Burger")!=a.second.end()&&a.second.find("Tavern")!=a.second.end())
            cout<<a.first<<endl;
    });

}
//this function will print person who did NOT visit Krusty-Burger and Home
void Surveillance::notKrustyBurgerAndHome() {
    cout<<"List the people who did NOT visit Krusty-Burger and Home"<<endl;
    for_each(begin(map1),end(map1),[](pair<string,set<string>>a){
        if(a.second.find("Krusty-Burger")==a.second.end()&&a.second.find("Tavern")==a.second.end())
            cout<<a.first<<endl;
    });

}
//this function will print person who  visited Krusty-Burger and School but did NOT visit Tavern and Home
void Surveillance::krustyBurgerAndSchoolNotTavernAndHome() {
    cout<<"List the people who visited Krusty-Burger and School but did NOT visit Tavern and Home";
    for_each(begin(map1),end(map1),[](pair<string,set<string>>a){
        if(a.second.find("Krusty-Burger")!=a.second.end()&&a.second.find("Tavern")==a.second.end()
           &&a.second.find("Home")==a.second.end())
            cout<<a.first<<endl;
    });


}
//this function will print person who visited all locations and remove them from your list and remove them
void Surveillance::printRemovePeopleAllLocation() {
    cout<<"List the people who visited all locations and remove them from your list";
    for_each(begin(map1),end(map1),[&](pair<string,set<string>>a){
        if(a.second.find("Krusty-Burger")!=a.second.end()
           &&a.second.find("Tavern")!=a.second.end()
           &&a.second.find("School")!=a.second.end()
           &&a.second.find("Home")!=a.second.end()){
            cout<<a.first<<endl;
            map1.erase(a.first);
        }
    });

}
//this function process action in order
void Surveillance::process() {
     printNameInOrder();
     krustyBurgerAndTavern();
     notKrustyBurgerAndHome();
     krustyBurgerAndSchoolNotTavernAndHome();
     printRemovePeopleAllLocation();
     printNameInOrder();

}

