#pragma once
#include "list.h"
#include <iostream>
#include <functional>

template <typename K, typename V>
class HashTable
{
private:
    int size, elem; //need prime number for better distributing
    List<K,V>*Htable;

public:
    HashTable():size(10007), elem(0)//closes prime to 10,004
    {
        Htable = new List<K,V>[size];
    }

    ~HashTable(){}

    int hashFunc(const K& key) const
    {
        auto hashVal = std::hash<K>{}(key);
        return hashVal % size;//get index
    }

    // double loadFactor() const{ return (double)elem/(double)size;}
    // bool isRehash(){return loadFactor() > 1.0;}
    // void rehash()
    // {
    //     int newSize=size*2;
    //     List<K,V>*newTable = new List<K,V>[newSize];//new array o lists for new size

    // }//dont need to rehash


    bool insert(const K& key, const V& val)
    {
        int i = hashFunc(key);
        Htable[i].insertAtFront(key, val);
        elem++;
        return true;
    }

    bool find(const K&key, V& val)
    {
        int i = hashFunc(key);
        return Htable[i].search(key, val);
    }
    bool findRef(const K& key, V*& pVal)//
    {
        int i = hashFunc(key);
        return Htable[i].searchRef(key, pVal);
    }
};