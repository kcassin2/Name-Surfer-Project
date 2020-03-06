#ifndef NAMESURFERDATABASEH
#define NAMESURFERDATABASEH
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <ios>
#include <iomanip>
using namespace std;
#include "linked_list.h"
#include "NameSurferEntry.h"
//h file including everything that is used inside of the .cpp of name surfer database



class NameSurferDataBase {

public:

    NameSurferDataBase(string filename);

    NameSurferEntry findEntry(string name);

private:

    linked_list<NameSurferEntry> database;

};
#endif