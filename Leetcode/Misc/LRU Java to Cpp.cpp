//Problem link - https://leetcode.com/problems/lru-cache/
#include<bits/stdc++.h>
using namespace std;
class LRUCache {
public:
    class node {
        public:
            int key;
            int val;
            node* next;
            node* prev;
    };
    
    node *head = new node();//this will remain fixed and head->next will give first element of the list
    node *tail = new node();//this will remain fixed and tail->prev will give last element from the list
    
    int cap;
    unordered_map<int, node*> m;//will save the address of the node mapped to its key
    
    LRUCache(int capacity) {
        cap = capacity;    
        head->next = tail;
        tail->prev = head;
    }
    
    void addnode(node* newnode) {//addition is happening at the front
        node* temp = head->next;//head->next gives first element in the doubly linked list
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }
    
    void deletenode(node* delnode) {
        node* delprev = delnode->prev;
        node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    
    int get(int key_) {
        int res = -1;
        if (m.find(key_) != m.end()) {//key exist in the cache
            node* accessedNode = m[key_];
            res = accessedNode->val;
            
            //now we have to delete the accessed node from its current place and insert it in the front as it has been
            //accessed now and it will be the least recently used node
            
            deletenode(accessedNode);//it will do it in O(1) time since we have direct address of node to be deleted since all
            					//the addresses of all nodes were hashed to their key value in the map
            m.erase(key_);
            addnode(accessedNode);//add it in the front
            m[key_] = head->next;//since node has been inserted in the front so head->next will give its address
        }
        return res;
    }
    
    void put(int key_, int value) {
        if (m.find(key_) != m.end()) {//already exist in cache and needs to be updated
            node* existingnode = m[key_];
            
            existingnode->val = value;//update its value
            
            //now since the element has been updated so it has to be as latest element by inserting it in front
			deletenode(existingnode);
            addnode(existingnode);
            m.erase(key_);
            m[key_] = head->next;
        }
        else {
            if (m.size() == cap) {//element not in cache and cache is full
                node* delnode = tail->prev;//last node will be deleted
                int delkey = delnode->key;
                deletenode(delnode);
                node* newnode = new node();
                newnode->key = key_;
                newnode->val = value;
                addnode(newnode);
                m.erase(delkey);
                m[key_] = newnode;
            }
            else{//element not in cache and cache is not full
                node* newnode = new node();
                newnode->key = key_;
                newnode->val = value;
                addnode(newnode);
                m[key_] = newnode;
            }
        }
    }
};
int main()
{
	return 0;
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
