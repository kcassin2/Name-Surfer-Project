    #include <iostream>
    #include <cstdlib>
    #include <ctime>
    #include <climits>
    #include <ios>
    #include<string>
    #include <iomanip>
    #include <fstream>
    #include <iostream>
    using namespace std;
    #include "NameSurferDataBase.h"
    #include "NameSurferEntry.h"
    #include "linked_list.h"
    int main(){
    //here I have placed variables used in the menu options
    //namez is for the cin statment that will allow user to enter in the names of babies
    string namez;
    //string search is for the cin statemnt for the user to enter in a name that they would like to search
    string search;
    //int year is for the cin statment for the user to enter in a year
    int year;
    //int compare is for the cin stamtent allowing user to enter in how many names they would like to compare
    int compare;
    //int menu is the variable that will allow the menu to stop when the user would like it to
    int menu =0; 
    
    
    //this reads in the file 
    NameSurferDataBase database("NamesData.txt");
    //string choice is for the cin statment allowing users to choose what option in the menu they want
    string choice;
    
    
    //the beginning of the menu, while loop, allowing user to enter in a choice and continue until they choose to stop
    while(menu==0){
    //menu intruction
    //these cout statments are for the user to read their options
    cout<<endl;
    cout<<"1:Enter a name to be searched."<<endl;
    cout<<"2:Enter a year"<<endl;
    cout<<"3:Exit"<<endl;
    cout<<"Enter a choice:";
    cin>>choice;
    
    if(choice=="1"){
    cout<<"Enter in a name:";
    cin>>search;
    
    NameSurferEntry obj= database.findEntry(search);
    
    if(obj.empty()==true){
    cout<<"Name Not Found"<<endl;
    
    }
    else{
    
    cout<<search<<endl;
    for(int i=1900; i<=2010 ;i+=10){
     string starz;
    int rank= obj.getRank(i);
    //cout<<obj.getName();
    
    for(int i =0; i<rank/10; i++){
    starz+="*";
    
    }
    cout<<i<<starz<<"-"<< rank<<endl;
    }
    
    }
    
    cout<<endl;
    
    }
    //option two allows user to enter in a year and compare however many names they want with that year
    else if(choice=="2"){
       
    cout<<"Enter a year:";
    cin>>year;
    cout<<"Enter how many Names you want to compare:";
    cin>>compare;
     string arr[compare];
     
          for(int i=0; i<compare; i++){
                cout<<"Enter name "<<i+1<<":";
    cin>>namez;
        arr[i]=namez;
        
    }
    cout<<endl;
     cout<<"You selected the decade "<<year<<endl;
       for(int i=0; i<compare; i++){
           
           
           NameSurferEntry obj= database.findEntry(arr[i]);
              int rank = obj.getRank(year);
              string star;
    for(int i =0; i<rank/10; i++){
        
    star+="*";
    
    
    }
   
      
   
    cout<<arr[i]<<"\t"<<star<<"-"<<rank<<endl;
    
    
    }
    
    
    //cout<<obj.getName();
    
    
    
    
    //cout<<endl;
    
    }
    
   
    //stops the menu
    else{ menu++;
    
    }
    }
    return 0;
    }