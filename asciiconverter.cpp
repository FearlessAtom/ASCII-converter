#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <sstream>
#include "atom.h"
using namespace std;
int main(){
    string path;
    do{
    cout << "Enter the path : ";
    getline(cin, path);
    if(touppercase(path) == "EXIT"){exit(0);}
    else if(!txtfileexists(path))
    {
        cout << "No files with such name! Do you wish to create one? [yes] [no]" << endl;
        bool foundtwo = false;
        do{
        cout << ">";
        string create;
        getline(cin, create);
        if(touppercase(create) == "YES"){txtfilecreate(path);foundtwo = true;}
        else if(touppercase(create) == "NO"){cout << "Then enter the path of an existing txt file!";foundtwo = true;}
        if(!foundtwo){cout << "Type yes or no depending on your choice!" << endl;}
        }while(!foundtwo);}
    }while(!txtfileexists(path));
    bool found = false;
    do{
    cout << "Option : ";string action;getline(cin, action);
    action = touppercase(action);
    if(action == "INPUT"){
        erase(path);
        chartoascii(path);
        found = true;}
    else if(action == "OUTPUT"){
        if(txtempty(path)){cout << "The file is empty!" << endl;
        continue;}
        cout << asciintochar(path) << endl;
        found = true;}
    else if(action == "ERASE"){
        erase(path);
        found = true;}
    else if(action == "EXIT"){exit(0);}
    else{cout << "Options : [input], [output], and [erase]" << endl;}
    }while(true);
    return 0;}