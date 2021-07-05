#include <iostream>
#include <list>
#include <unordered_map>

using std::endl;
using std::cout;
using std::list;
using std::unordered_map;

class LRUCache {  //this version only pass 21/22 test cases
private:
    unsigned int capacity;
    list<int> mylist;
    unordered_map<int, int> myMap;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        int ret;
        if (myMap.count(key) > 0) {  //average O(1)
            ret = myMap[key];
            this->updateList2(key);
        } else {
            ret = -1;
        }
        return ret;
    }
    
    void put(int key, int value) {
        if (myMap.count(key) > 0) {
            myMap[key] = value;
            this->updateList2(key);
        } else {
            if(mylist.size() < capacity) {
                mylist.push_front(key);   // O(1)
                myMap.insert(std::pair<int, int>(key ,value)); //average O(1)
            } else {
                // delete least recently used key
                int backKey = mylist.back();
                mylist.pop_back();
                myMap.erase(myMap.find(backKey));
                // add new key since the current capacity is big enough
                mylist.push_front(key);
                myMap.insert(std::pair<int, int>(key ,value));
            }
        }
    }

    void updateList(int key) {
        list<int>::iterator it = mylist.begin();
        while(it != mylist.end()) {  //O(n)
            if (*it == key) break;
            it++;
        }
        mylist.erase(it);
        mylist.push_front(key);
    }

    void updateList2(int key) { 
        mylist.remove(key);    //O(n)
        mylist.push_front(key);
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