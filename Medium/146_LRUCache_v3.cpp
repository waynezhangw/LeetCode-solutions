#include <iostream>
#include <list>
#include <unordered_map>

using std::endl;
using std::cout;
using std::list;
using std::unordered_map;
using std::pair;
using std::make_pair;

//this version faster 30.64% than and less than 22.50%
//for those who has better time complexity is to implement double list themselves 
//instead of using standard library
class LRUCache {  //this version is directly from comments
private:
    unsigned int capacity;
    list< pair<int, int> > mylist;
    unordered_map<int, list<pair<int, int>>::iterator > myMap;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        int ret;
        if (myMap.count(key) > 0) {  //average O(1)
            ret = (*myMap[key]).second;
            this->updateList(key, ret);
        } else {
            ret = -1;
        }
        return ret;
    }
    
    void put(int key, int value) {
        if (myMap.count(key) > 0) {
            // when key already exists
            this->updateList(key, value);
        } else {
            mylist.push_front( make_pair(key, value) );   // O(1)
            myMap[key] = mylist.begin(); //average O(1) is similar to insert operation
            if(mylist.size() > capacity) {
                // delete least recently used key
                myMap.erase( mylist.back().first );  // O(1) 
                mylist.pop_back();
            }
        }
    }

    void updateList(int key, int value) { 
        // this is O(1) since I can know which position to erase in O(1) time
        mylist.erase(myMap[key]);
        mylist.push_front( make_pair(key, value) );
        myMap[key] = mylist.begin();
    }
};


//I couldn't really understand the code logic until I put it in VS Studio and debug it line by line

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