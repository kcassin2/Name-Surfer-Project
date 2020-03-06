#ifndef NAMESURFERENTRYCPP
#define NAMESURFERENTRYCPP
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <ios>
#include <iomanip>
using namespace std;
#include "NameSurferDataBase.h"
#include "linked_list.h"
#include "NameSurferEntry.h"

    
    //bool operator for less than
    
    bool NameSurferEntry::operator< (NameSurferEntry left){
        if(left.name< this->name){
            return true;
        }
        else{
            return false;
        }
        
        
    }
//bool operator for greater than
    bool NameSurferEntry::operator> (NameSurferEntry left){
        if(left.name> this->name){
            return true;
        }
        else{
            return false;
        }
        
    }
//bool operator for less than equal to
    bool NameSurferEntry::operator<= (NameSurferEntry left){
        if(left.name<= this->name){
            return true;
        }
        else{
            return false;
        }
        
    }
//bool operator for greater than equal to
    bool NameSurferEntry::operator>= (NameSurferEntry left){
        if(left.name>= this->name){
            return true;
        }
        else{
        return false;
        }
    }
//bool operator for not
    bool NameSurferEntry::operator!= (NameSurferEntry left){
        if(left.name!= this->name){
            return true;
        }
        else{
            return false;
        }
        
    }
//bool operator for equal to
    bool NameSurferEntry::operator== (NameSurferEntry left){
        if(left.name== this->name){
            return true;
        }
        else{
            return false;
        }
        
    }
    //rankadd used to add the rank after the decades in the name surfer database class
    
   void NameSurferEntry::rankadd(int ranking){
     rank.push_back(ranking);   
     
    }

    NameSurferEntry::NameSurferEntry(){
        
    }

    NameSurferEntry::NameSurferEntry(string line){
        
        name = line;
    }
//sets the name equal to the baby name
    void NameSurferEntry::setName(string name){
         this->name=name;
    }
//returns the baby names
    string NameSurferEntry::getName(){
        return name;
    }
//gets the rank of the baby names in the vector
    int NameSurferEntry::getRank(int year){
        int temp=1900;
        for(int i=0; i<rank.size(); i ++){
            if (year!= temp){
                temp+=10;
            }
            else if(year==temp){
                return rank.at(i);
            }
        }
        //return year
    }
//checks if empty and returns true if so 
    bool NameSurferEntry::empty(){
        if(name==""){
            return true;
            
        }
        else{
            return false;
        }
        
    }
    #endif