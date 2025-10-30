#include "data.h"

void Data::parseData(string &line)
{

    int begin=0, end=0;
    end = line.find(',', begin);
    ID = line.substr(begin, end-begin);
        
    begin=end+1;//move past comma

    if(line[begin] =='"')//if name is quoted
    {
        name = parseQuotedName(line, begin);
    }
    else
    {
        name = parseRegName(line, begin);
    }

    //now i need to skip 2 ","
    end = line.find(',', begin);//1st ,
    end = line.find(',', end+1);//2nd ,
    begin = end+1; // move to after the 2nd comma


    end= line.find(',', begin);
    string categoryLine = line.substr(begin, end - begin);
    if(categoryLine == "")categoryLine="N/A";
    //have the categories as a whole string
    //now i just need to trim down each section
    //removinf the extra spaces as well.


    if(!categoryLine.empty())
    {
        parseCategories(categoryLine, categories, catCount);
    }

}

void Data::parseCategories(const string &categoryLine, string categories[], int &catCount)
{
    catCount=0;
    int catBegin=0;
    while(catCount<10)
    {
        int bar = categoryLine.find('|', catBegin);
        string section;
        if (bar == string::npos)//no bars
        {
            section = categoryLine.substr(catBegin);
            
        }
        else
        {
            section = categoryLine.substr(catBegin, bar - catBegin);//up to bar

        
        }

        //removing " " from beggining and enf of section
        if(section[0] == ' ')//beginning space
        {
            section = section.substr(1);//start from index 1
        }
        if(section[section.length()-1] == ' ')//end space
        {
            section = section.substr(0, section.length() -1); //removing the space
        }
        
        categories[catCount] = section;
        catCount++;
        if (bar == string::npos)
        {
            break;
        }
        catBegin = bar + 1;

    }

    if (catCount == 0)
    {
        categories[0]="N/A";
        catCount = 1;
    }

}

string Data::parseQuotedName(const string &line, int &begin)
{
    int end;
    begin++; // skip first "
    end = line.find('"', begin);

    
    while (end != string::npos)// keep searching until we find the real closing quote
    {
        
        if (end + 1 < line.size() && line[end + 1] == '"')//if we see a double quote ""
        {
            end = line.find('"', end + 2);//skip both and keep going
        }
        else
        {
            break; //found the actual closing "
        }
    }

    if (end == string::npos)
        end = line.size();

    string name = line.substr(begin, end - begin);

    end = line.find(',', end + 1);//move past the closing " and ,
    begin = end + 1;

    return name;
}

string Data::parseRegName(const string &line, int &begin)
{
    int end;
    end= line.find(',', begin);
    name = line.substr(begin, end-begin);
    begin = end +1;
    return name;
}
