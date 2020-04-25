//
//  146LRU.cpp
//  test
//
//  Created by wangxue on 2019/12/26.
//  Copyright © 2019 wangxue. All rights reserved.
//

#include <list>
#include <utility>
#include <unordered_map>
#include <map>
using namespace std;

class LRUCache {
private:
    int cap;
    // Double linked list with pair(key, value)
    list<pair<int, int>> cache;
    // hash table, map key to pair(key, value) in the cache
    unordered_map<int, list<pair<int, int>>::iterator> map;
public:
    LRUCache(int capacity) {
        this->cap = capacity;
    }
    
    int get(int key) {
        auto it = map.find(key);
        // if key is not in the map
        if (it == map.end()) return -1;
        // if key is in the map, put (k, v) in the head
        pair<int, int> kv = *map[key];
        cache.erase(map[key]);
        cache.push_front(kv);
        // update the location of (key, value) in the cache
        map[key] = cache.begin();
        // return pair value
        return kv.second;
    }
    
    void put(int key, int value) {

        // whether key is in the map
        auto it = map.find(key);
        if (it == map.end()) {
            // key is not in the map, then judge cache is full ?
            if (cache.size() == cap) {
                // cache is full, delete the tail
                // update the cache and map
                auto lastPair = cache.back();
                int lastKey = lastPair.first;
                map.erase(lastKey);
                cache.pop_back();
            }
            // cache is not full, add (key,value) directly
            cache.push_front(make_pair(key, value));
            map[key] = cache.begin();
        } else {
            // key exists,update value and put it in the head
            cache.erase(map[key]);
            cache.push_front(make_pair(key, value));
            map[key] = cache.begin();
        }
    }
};
