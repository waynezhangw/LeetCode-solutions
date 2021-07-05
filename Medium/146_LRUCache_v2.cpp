#include <iostream>
#include <list>
#include <unordered_map>

using std::endl;
using std::cout;
using std::list;
using std::unordered_map;

//this version faster than 21.68% and less than 10.25%
class LRUCache {  //this version is based on a method from comments
private:
    unsigned int capacity;
    list<int> mylist;
    unordered_map<int, int> myMap;

    //mainly add this to speed up erase from list
    unordered_map<int, list<int>::iterator> key2posMap;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        int ret;
        if (myMap.count(key) > 0) {  //average O(1)
            ret = myMap[key];
            this->updateList(key);
        } else {
            ret = -1;
        }
        return ret;
    }
    
    void put(int key, int value) {
        if (myMap.count(key) > 0) {
            myMap[key] = value;
            this->updateList(key);
        } else {
            if(mylist.size() < capacity) {
                mylist.push_front(key);   // O(1)
                key2posMap[key] = mylist.begin();
                myMap[key] = value; //average O(1) is similar to insert operation
            } else {
                // delete least recently used key
                myMap.erase(mylist.back());  // O(1) 
                key2posMap.erase(mylist.back()); // similar to key2posMap.erase(key2posMap.find(backKey))
                mylist.pop_back();
                // add new key since the current capacity is big enough
                mylist.push_front(key);
                key2posMap[key] = mylist.begin();
                myMap[key] = value;
            }
        }
    }

    void updateList(int key) { 
        mylist.erase(key2posMap[key]);  // this is O(1)
        mylist.push_front(key);
        key2posMap[key] = mylist.begin();
    }
};


int main() {
    LRUCache lRUCache  = LRUCache(2);
    lRUCache.put(2, 1); // cache is {1=1}
    lRUCache.put(2, 2); // cache is {1=1, 2=2}
    cout << lRUCache.get(1) << endl;    // return 1
    lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    cout << lRUCache.get(2) << endl;    // returns -1 (not found)
    lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    cout << lRUCache.get(1) << endl;    // return -1 (not found)
    cout << lRUCache.get(3) << endl;    // return 3
    cout << lRUCache.get(4) << endl;    // return 4
    return 0;
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */