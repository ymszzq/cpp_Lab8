#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <algorithm>
#include "Surveillance.h"
using namespace std;



int main() {
    Surveillance surveillance("peoplePlaces.txt");
    surveillance.process();
    return 0;
}
