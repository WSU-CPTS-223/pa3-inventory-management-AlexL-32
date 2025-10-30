
template<typename K, typename V>
class Node
{
    private:
    Node*pNext;
    K key;
    V val;
    public:
    Node(const K&newKey, const V& newVal): key(newKey), val(newVal), pNext(nullptr) {}

    Node* getNextPtr() const { return pNext; }
    void setNextPtr(Node* newNext) { pNext = newNext; }

    K getKey() const { return key; }
    V getVal() const { return val; }
    V&getVal() {return val;}//need to modify value in hashtable
    const V& getValRef() const {return val;}
    void setVal(const V& newVal) {val = newVal;}
    void setKey(const K& newKey) { key = newKey; }
};