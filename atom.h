#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
string touppercase(string thing)
{
    for(int index = 0; index < thing.size(); index++){
        thing[index] = toupper(thing[index]);
    }
    return thing;
}
void erase(string path)
{
    fstream file;
    file.open(path, ios::out);
    file.close();
}
void chartoascii(string path)
{
    fstream file;
    file.open(path, ios::app | ios::out | ios::in);
    cout << ">";string something;getline(cin, something);
    for(int index = 0; index < something.size(); index++){
        int number = static_cast<int>(something[index]);
        file.seekp(0, ios::end);
        file << number << " ";}
    file.close();
}
bool txtfileexists(string path)
{
    ifstream file(path);
    return file.good();
}
string asciintochar(string path)
{
    fstream file; file.open(path, ios::in);
    string line, token, output = "";
    getline(file, line);
    istringstream iss(line);
    while(getline(iss, token, ' ')){
        int asciivalue = stoi(token);
        char character = static_cast<char>(asciivalue);
        output = output + static_cast<char>(character);}
    file.close();
    return output;
}
int txtempty(string path)
{
    fstream file; file.open(path, ios::in);
    if(file.peek() == ifstream::traits_type::eof()){
        file.close();
        return 1;}
    file.close();
    return 0;
}
void txtfilecreate(string path)
{
    fstream file;
    file.open(path, ios::out);
    file.close();
}