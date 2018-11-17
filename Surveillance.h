//
// Created by gmziv on 2018-11-16.
//

#ifndef LAB8_SURVEILLANCE_H
#define LAB8_SURVEILLANCE_H

#include <set>
#include <map>
#include <iostream>
#include <fstream>
using namespace std;
class Surveillance {
private:
    map<string,set<string>> map1;
public:
Surveillance(string);
set<string> seperateString(string locationString);
void printNameInOrder();
void krustyBurgerAndTavern();
void notKrustyBurgerAndHome();
void krustyBurgerAndSchoolNotTavernAndHome();
void printRemovePeopleAllLocation();

void process();


};


#endif //LAB8_SURVEILLANCE_H
