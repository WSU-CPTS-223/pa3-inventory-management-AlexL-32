#pragma once
#include <string>
#include "list.h"
using std::string;
class Data
{
private:
    string name,ID,categories[10];
    int catCount;

public:

    Data(): name(""), ID(""), catCount(0){}

    string getName() const {return name;}
    string getID() const {return ID;}
    int getCatCount() const{return catCount;}
    string getOneCategory(int index) const{return categories[index];}
    // i shouldnt really need setters for this



    // Only need ID,name, and category from each line and each line seems to have 
    // empty fields for brand name and asin so all i need to do is parse ID and name
    // skip 2 commas thenparse category. I dont think i spot any empty ID name, or category fields
    // but ill try to handle that just in case
    void parseData(string& line);
    void parseCategories(const string& categoryLine, string categories[], int& catCount);
    string parseQuotedName(const string&line , int& begin);
    string parseRegName(const string&line , int& begin);
};