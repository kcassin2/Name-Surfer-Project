#ifndef NAMESURFERDATABASECPP
#define NAMESURFERDATABASECPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <ios>
#include <iomanip>
#include<fstream>
#include <string>
#include <ostream>
using namespace std;
#include "linked_list.h"
#include "NameSurferEntry.h"
#include "NameSurferDataBase.h"

NameSurferDataBase::NameSurferDataBase(string filename){
     
    //code for reading in a file 
ifstream data(filename);
//string baby is object name 
string baby;
//new name surfer entry created
NameSurferEntry obj(baby);
//initializing the decades
int decade1, decade2, decade3, decade4, decade5, decade6, decade7, decade8, decade9,decade10, decade11, decade12;
//reading in the file and the decades
if(data.is_open()){
    //while loop allowing parsing of file
    while(data>>baby>>decade1>>decade2>>decade3>>decade4>>decade5>>decade6>>decade7>>decade8>>decade9>>decade10>>decade11>>decade12){
        NameSurferEntry obj(baby);
        obj.rankadd(decade1);
        obj.rankadd(decade2);
        obj.rankadd(decade3);
        obj.rankadd(decade4);
        obj.rankadd(decade5);
        obj.rankadd(decade6);
        obj.rankadd(decade7);
        obj.rankadd(decade8);
        obj.rankadd(decade9);
        obj.rankadd(decade10);
        obj.rankadd(decade11);
        obj.rankadd(decade12);
        //
        database.InsertRear(obj);
        
    }
    //closing out file reader
    data.close();
}
     
     
 }

     NameSurferEntry NameSurferDataBase:: findEntry(string name){
         //the chars are for correcting strings, toupper and tolower in any specific case
         string temp;
         
        char first= name.at(0);
        first= toupper(first);
        temp+=first;
     
        for(int i=1;i<name.length();i++){
               char next = name.at(i);
           next=tolower(next);
            temp+=next;
        }
        name = temp;
          NameSurferEntry search;
        search.setName(name);
        if(database.Search(search)==true){
            return search;
        }
      else{
          search.setName("");
          return search;
      }
        
           //checks if the name is valid
// if(name==empty()){
//     return true;
// search.setName("");
// }

//         else{
//            
//             return search;
return temp;
        }
        //creating temporary name surfer entry, searching for that entry and retruning that entry
      
        
        
        
        
    
    #endif