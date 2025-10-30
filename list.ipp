#include "list.h"

template <typename K, typename V>
void List<K,V>::insertAtFront(const K& key,const V& val)
{

    Node<K,V>* pMem = new Node<K,V>(key,val);
    if(isEmpty())
    {
        pHead = pMem;
    }
    else{
        pMem->setNextPtr(pHead);
        pHead = pMem;

    }
}

template <typename K, typename V>
void List<K,V>::destroyList()
{
    Node<K,V>*pCur = pHead;
    while(pCur != nullptr)
    {
        Node<K,V>*temp = pCur;
        pCur = pCur->getNextPtr();

        delete temp;
    }

    pHead = nullptr;
}

template <typename K, typename V>
bool List<K,V>::search(const K& key, V& val)
{
    bool status = false;
    Node<K,V>* pCur = pHead;
    while (pCur != nullptr)
    {
        if(pCur->getKey() == key)
        {
            val = pCur->getVal();
            return status = true;
        }


        pCur=pCur->getNextPtr();
    }


    return status;
}

template <typename K, typename V>
inline bool List<K, V>::searchRef(const K &key, V *&pVal)
{
    bool status = false;
    Node<K,V>* pCur = pHead;
    while (pCur != nullptr)
    {
        if(pCur->getKey() == key)
        {
            pVal = &pCur->getVal();//address of value in node
            return status = true;
        }


        pCur=pCur->getNextPtr();
    }


    return status;
}
