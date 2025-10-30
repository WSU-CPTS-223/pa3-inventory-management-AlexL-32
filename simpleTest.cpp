#include <iostream>
#include <cassert>
#include <string>
#include "list.h"
#include "hashTable.h"
#include "data.h"

using namespace std;
void test_simpleParse()// no commas in string
{
    cout <<"Simple Parse Test:" <<endl;
    // ID,Name,Brand,ASIN,Categories,...
    string line = "abcd123456,\"Real Fake Doors!\",,,Real | Fake | Dumb";
    Data d;
    d.parseData(line);

    assert(d.getID() == "abcd123456");
    assert(d.getName() == "Real Fake Doors!");
    assert(d.getCatCount() == 3);
    assert(d.getOneCategory(0) == "Real");
    assert(d.getOneCategory(1) == "Fake");
    assert(d.getOneCategory(2) == "Dumb");
    cout << "\tSimple Parse Passed.\n" <<endl;
}

void test_quotedNameParse()//commas in string
{
    cout << "Quoted Name Parse Test:" <<endl;
    string line = "0987654321,\"The One, True Ring Replica\",,,Movies & TV | Collectibles";
    Data d;
    d.parseData(line);

    assert(d.getID() == "0987654321");

    assert(d.getName() == "The One, True Ring Replica");
    assert(d.getCatCount()==2);
    assert(d.getOneCategory(0) == "Movies & TV");

    assert(d.getOneCategory(1) == "Collectibles");

    cout<< "\tQuoted Name Parse Passed.\n"<< endl;
}

void test_MissingCategoryParse()
{
    cout << "Testing Missing Category Parse:" <<endl;

    string line = "6767676767,\"Invisible Item\",,,,";
    Data d;
    d.parseData(line);

    assert(d.getID() == "6767676767");
    assert(d.getName() == "Invisible Item");
    assert(d.getCatCount() >= 1);

    assert(d.getOneCategory(0) == "N/A");

    cout <<"\tMissing Category Parse Passed.\n" << endl;
}

void test_CategorySpaceTrim()
{
    cout << "Testing Category whitespace trimming:" << endl;

    string line = "6969696969,\"Kids Dinner Table\",,,Home & Kitchen | Furniture | Toys & Games";
    Data d; d.parseData(line);

    assert(d.getCatCount() == 3);
    
    assert(d.getOneCategory(0) == "Home & Kitchen");
    assert(d.getOneCategory(1) == "Furniture");
    assert(d.getOneCategory(2) == "Toys & Games");
    cout << "\tCategory Space trim Passed.\n" << endl;
}

void test_ListInsertAtFrontAndSearch()
{
    cout<< "Testing InsertAtFront and Search:" <<endl;

    List<string,int> obj;
    obj.insertAtFront("Phone", 10);
    obj.insertAtFront("Banana", 20);
    obj.insertAtFront("Paper", 30);

    int value = 0;
    assert(obj.search("Banana", value) && value == 20);
    assert(obj.search("Paper", value) && value == 30);
    assert(!obj.search("Candy", value)); // candy shouldnt exist

    cout << "\tInsertAtFront and Search Passed.\n" << endl;
}

void test_HashInsertAndFind()
{
    cout << "Testing Hash insert and find:" << endl;

    HashTable<string,string> Htable;
    string value;

    Htable.insert("111111111", "Random Item");
    Htable.insert("2222222222", "Mouse");
    Htable.insert("333333333", "Keyboard");

    assert(Htable.find("111111111", value) && value == "Random Item");
    assert(Htable.find("333333333", value) && value == "Keyboard");
    assert(!Htable.find("44444444444", value)); // doesn’t exist

    cout << "\tHash insert and find Passed.\n" << endl;
}

int main()
{
    test_simpleParse();
    test_quotedNameParse();
    test_MissingCategoryParse();
    test_CategorySpaceTrim();
    test_ListInsertAtFrontAndSearch();
    test_HashInsertAndFind();
    cout << "All tests passed!" <<endl;
    return 0;
}