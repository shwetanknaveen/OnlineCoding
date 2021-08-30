//Problem link - https://leetcode.com/problems/lru-cache/submissions/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class LRUCache {
public:
    int capacity;
    LRUCache(int capacity) {
        LRUCache::capacity = capacity;
    }
    map<int,int> data;
    deque<int> keysUsageOrder;
    int get(int key) {
        if(data.find(key)==data.end()) return -1;
		else
        {
        	//since element is being accessed hence usage order has to be updated
        	for (deque<int>::iterator iter = keysUsageOrder.begin(); iter != keysUsageOrder.end() ; iter++)
            {
                if(*iter == key)
                {
                keysUsageOrder.erase(iter);
                keysUsageOrder.push_back(key);//now it's in the end as latest used block
                break;
                }
            }
            return data.find(key)->second;
        }
    }
    
    void put(int key, int value) {
        if(data.find(key) != data.end())//key already exist
        {
            data.find(key)->second = value;
            
            //in this case update has to occur in the usage order
            for (deque<int>::iterator iter = keysUsageOrder.begin(); iter != keysUsageOrder.end() ; iter++)
            {
                if(*iter == key)
                {
                keysUsageOrder.erase(iter);
                keysUsageOrder.push_back(key);//now it's in the end as latest used block
                break;
                }
            }
        }
        else //key doesn't exit
        {
            if(data.size() == capacity)//cache is full
            {
                data.erase(keysUsageOrder.front());//the key which was least recently used
                keysUsageOrder.pop_front();
            }
            data.insert(pair<int,int>(key,value));
            keysUsageOrder.push_back(key);
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
