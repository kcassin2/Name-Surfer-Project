#ifndef NAMESURFERENTRYH
#define NAMESURFERENTRYH
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <ios>
#include <iomanip>
using namespace std;
#include <vector>


//.h file included in name surfer entry.cpp and database.cpp, includes everyhting used in the namesurfer entry.cpp

class NameSurferEntry {

    friend ostream & operator<<(ostream &out, NameSurferEntry temp);

public:

    bool operator< (NameSurferEntry left);

    bool operator> (NameSurferEntry left);

    bool operator<= (NameSurferEntry left);

    bool operator>= (NameSurferEntry left);

    bool operator!= (NameSurferEntry left);

    bool operator== (NameSurferEntry left);
    
void rankadd(int ranking);
   NameSurferEntry();

    NameSurferEntry(string line);

    void setName(string name);

    string getName();

    int getRank(int year);

    bool empty();

   

private:

    vector<int>    rank;

    string        name;

   

};
#endif