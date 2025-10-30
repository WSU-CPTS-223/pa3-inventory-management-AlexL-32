#include <iostream>
#include <string>
#include <fstream>
#include "data.h"
#include "hashTable.h"

using namespace std;

HashTable<string,Data> find_index;
HashTable<string, List<string,Data>> find_cat_index;

void printHelp()
{
    cout << "Supported list of commands: " << endl;
    cout << " 1. find <inventoryid> - Finds if the inventory exists. If exists, prints details. If not, prints 'Inventory not found'." << endl;
    cout << " 2. listInventory <category_string> - Lists just the id and name of all inventory belonging to the specified category. If the category doesn't exists, prints 'Invalid Category'.\n"
         << endl;
    cout << " Use :quit to quit the REPL" << endl;
}

bool validCommand(string line)
{
    return (line == ":help") ||
           (line.rfind("find", 0) == 0) ||
           (line.rfind("listInventory") == 0);
}

void evalCommand(string line)
{
    if (line == ":help")
    {
        printHelp();
    }
    // if line starts with find
    else if (line.rfind("find", 0) == 0)
    {
        // Look up the appropriate datastructure to find if the inventory exist
        string id =line.substr(5);
        Data product;

        if(!find_index.find(id, product))//not in table
        {
            cout<<"Inventory/Product not found"<<endl;
            return;
        }

        cout<<"Uniq ID: "<< product.getID() <<endl;
        cout<<"Product Name: "<< product.getName() <<endl;

        cout<<"Categories: "<<endl;
        for(int i=0; i< product.getCatCount(); i++)
        {
        cout << product.getOneCategory(i) << endl;
        }


    }
    // if line starts with listInventory
    else if (line.rfind("listInventory") == 0)
    {
        // Look up the appropriate datastructure to find all inventory belonging to a specific category
        string category = line.substr(14);

        List<string, Data>* pList = nullptr;


        if (!find_cat_index.findRef(category, pList) || pList == nullptr) 
        {
            cout << "Invalid Category" << std::endl;
            return;
        }

        Node<string, Data>* pCur = pList->getHeadPtr();
        if (!pCur)
        {
            cout << "Invalid Category" << endl;
            return;
        }

        cout<< "All Products for Category - "<< category << endl;
        while (pCur)
        {
            Data product = pCur->getValRef();
            cout<< "ID: " << product.getID() << "\tProduct Name: " << product.getName() <<endl;
            pCur= pCur->getNextPtr();
        }
        
        return;
    }
}

void bootStrap()
{
    cout << "\n Welcome to Amazon Inventory Query System" << endl;
    cout << " enter :quit to exit. or :help to list supported commands." << endl;
    cout << "\n> ";

    // TODO: Do all your bootstrap operations here
    // example: reading from CSV and initializing the data structures
    // Don't dump all code into this single function
    // use proper programming practices

    ifstream infile("marketing_sample_for_amazon_com-ecommerce__20200101_20200131__10k_data.csv");
    if(!infile)
    {
        cout<<"Couldn't open file."<<endl;
        return;
    }

    string line;
    getline(infile, line);

    while(getline(infile, line))
    {
        Data product;
        product.parseData(line);
        find_index.insert(product.getID(), product);



        for (int i = 0; i < product.getCatCount(); i++)
        {
            string category = product.getOneCategory(i);

            if(category != "N/A" && !category.empty())
            {
                List<string, Data>* pList = nullptr;
                if (find_cat_index.findRef(category, pList))//if found in table
                {
                    pList->insertAtFront("", product);//insert the product into the list
                } 
                else 
                {
                    List<string, Data> newList; // created new list if not found
                    newList.insertAtFront("", product);
                    find_cat_index.insert(category, newList);//insert created list in hTable
                }
            }
        }
        
    }


    infile.close();
}

int main(int argc, char const *argv[])
{
    string line;
    bootStrap();
    while (getline(cin, line) && line != ":quit")
    {
        if (validCommand(line))
        {
            evalCommand(line);
        }
        else
        {
            cout << "Command not supported. Enter :help for list of supported commands" << endl;
        }
        cout << "> ";
    }
}