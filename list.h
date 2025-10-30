 #pragma once
 #include "node.h"

template <typename K, typename V>
class List
{
    private:
    Node<K,V>*pHead;


    public:
    List():pHead(nullptr){}
    ~List() { destroyList(); }
    
    Node<K,V>* getHeadPtr() const {return pHead; }
    bool isEmpty() { return pHead == nullptr;}
    void insertAtFront(const K& key,const V&val);
    void destroyList();
    bool search(const K& key, V& val);
    bool searchRef(const K& key, V*& pVal);//return pointer to value

    //difference between search and searchRef is that search returns a copy of value while searchRef
    //returns a pointer to value in the node so it can be changed directly

};

#include "list.ipp"