//Problem link - https://leetcode.com/problems/lfu-cache/

//Video Explanation - https://www.youtube.com/watch?v=0PSB9y8ehbk&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=78
//Code Explanation - https://www.youtube.com/watch?v=mzqHlAW7jeE&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=79


/*
LFU will be implemented by implementing LRU for each list for a frequency.
That is, freqListMap will keep the list of nodes having certian frequency as following

freq1 --> <List of nodes having frequency freq1>
freq2 --> <List of nodes having frequency freq2>
	...and so on
	
Now we del nodes from this map (if cache is full). We del first from list having freqency = minFreq
When certian node is get() or updated or newly created then its count and position in this map is accordingly updated
*/
struct Node {
    int key, value, cnt;
    Node *next; 
    Node *prev;
    Node(int _key, int _value) {
        key = _key;
        value = _value; 
        cnt = 1; 
    }
}; 
struct List {
    int size; 
    Node *head; 
    Node *tail; 
    List() {
        head = new Node(0, 0); 
        tail = new Node(0,0); 
        head->next = tail;
        tail->prev = head; 
        size = 0;
    }
    
    void addFront(Node *node) {
        Node* temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
        size++; 
    }
    
    void removeNode(Node* delnode) {
        Node* delprev = delnode->prev;
        Node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
        size--; 
    }
    
    
    
};
class LFUCache {
    map<int, Node*> keyNode; 
    map<int, List*> freqListMap; 
    int maxSizeCache;
    int minFreq; 
    int curSize; 
public:
    LFUCache(int capacity) {
        maxSizeCache = capacity; 
        minFreq = 0;
        curSize = 0; 
    }
    void updateFreqListMap(Node *node) {
        keyNode.erase(node->key); //Not necessary as node is not changed, just its mappings are being changed
        freqListMap[node->cnt]->removeNode(node);//removeNode() is member function of List class and freqListMap[freq] will 
        										//return List pointer of that list which holds list of those nodes which
        										//have frequency = freq hence we call removeNode() in this way
        if(node->cnt == minFreq && freqListMap[node->cnt]->size == 0) {//this node whose frequency has to be updated
        															//has count = minimum frequency and deleting it makes
        															//list size 0 for that frequency then minFreq will be
        															//now +1 as ONLY this node had minimum freq and this
        															//node has now +1 frequency
            minFreq++; 
        }
        
        List* nextHigherFreqList = new List();
        if(freqListMap.find(node->cnt + 1) != freqListMap.end()) {//if there is already a list existing for freq value
        															//=new freq of this node then initialise this with it
            nextHigherFreqList = freqListMap[node->cnt + 1];
        } 
        node->cnt += 1; //increase the count
        nextHigherFreqList->addFront(node); //add this node in front of that list
        freqListMap[node->cnt] = nextHigherFreqList; //update the freqListMap with new list
        keyNode[node->key] = node;//update the new address....not necessary to delete and update in keyNode map as node is
        						//not changing here. It's just its mapping getting changed.
    }
    
    int get(int key) {
        if(keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key]; 
            int val = node->value; 
            updateFreqListMap(node); 
            return val; 
        }
        return -1; 
    }
    
    void put(int key, int value) {
        if (maxSizeCache == 0) {
            return;
        }
        if(keyNode.find(key) != keyNode.end()) {//key already exists in the cache and hence its value will be updated
            Node* node = keyNode[key]; 
            node->value = value; 
            updateFreqListMap(node); 
        }
        else {// new value has to be added which is not in the cache
            if(curSize == maxSizeCache) {//cache full
                List* list = freqListMap[minFreq]; //list will now point to list of those nodes which have minimum frequency
                keyNode.erase(list->tail->prev->key); //Since additions have been done on front end hence LRU node will be at the tail
                freqListMap[minFreq]->removeNode(list->tail->prev);
                curSize--; 
            }
            curSize++; //new node is being added
            
            minFreq = 1;//this element is being added for the first time hence it will have minFreq = 1 
            List* listFreq = new List(); 
            if(freqListMap.find(minFreq) != freqListMap.end()) {//if there is already a list having nodes with freq=minFreq then initialise this with that list
                listFreq = freqListMap[minFreq]; 
            }
            Node* node = new Node(key, value); 
            listFreq->addFront(node);//add this node to the front
            keyNode[key] = node; //save its address in the map
            freqListMap[minFreq] = listFreq; //update the list in the map with new updated list
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
 
 
 
 
 //TRYING BY SELF ON LEETCODE
 /*
LFU will be implemented by implementing LRU for each list for a frequency.
That is, mpFreqList will keep the list of nodes having certian frequency as following

freq1 --> <List of nodes having frequency freq1>
freq2 --> <List of nodes having frequency freq2>
	...and so on
	
Now we del nodes from this map (if cache is full). We del first from list having freqency = minFreq
When certian node is get() or updated or newly created then its count and position in this map is accordingly updated
*/
 class Node
{
    public:
    int key;
    int value;
    int count;
    Node *prev,*next;
    
    Node(int key,int value)
    {
        this->key = key;
        this->value = value;
        this->count = 1;
    }
};
class List
{
    public:
    Node *head;
    Node *tail;
    int size;
    
    List()
    {
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    
    void addNodeRear(Node *node)//add nodes to the rear end
    {
        node->next=tail;
        tail->prev->next = node;
        node->prev = tail->prev;
        tail->prev = node;
        size++;//size of this frequency list will increase by 1
    }
    
    void delNode(Node *node)
    {
        Node *delNodePrev = node->prev;
        Node *delNodeNext = node->next;
        delNodePrev->next = delNodeNext;
        delNodeNext->prev = delNodePrev;
        size--;//size of this frequency list will decrease by 1
    }
};
class LFUCache {
public:
    int currSize;
    int capacity;
    int minFreq;
    unordered_map<int,Node*> mpKeyAddr;
    unordered_map<int,List*> mpFreqList;
    
    LFUCache(int capacity) 
    {
        this->capacity = capacity;
        currSize = 0;
        minFreq = 0;
    }
    
    void updateFreqList(Node *node)
    {
        mpFreqList[node->count]->delNode(node);//delete the node from that freq list
        
        if(minFreq == node->count && mpFreqList[node->count]->size == 0)//this node whose frequency has to be updated
        	minFreq++;												//has count = minimum frequency and deleting it makes
        															//list size 0 for that frequency then minFreq will be
        															//now +1 as ONLY this node had minimum freq and this
        															//node has now +1 frequency
            
        node->count = node->count + 1;//new frequency of node
        List *newList = new List();
        
		if(mpFreqList.find(node->count) != mpFreqList.end())//if there is already a list existing for freq value
        	newList = mpFreqList[node->count];				//=new freq of this node then initialise this with it
            
        
        newList->addNodeRear(node);//add this node in rear of the new list
        mpFreqList[node->count] = newList;//update the mpFreqList for this frequency with the new updated list
    }
    
    int get(int key) {
        if(mpKeyAddr.find(key)==mpKeyAddr.end())
            return -1;
        
        int retVal = mpKeyAddr[key]->value;
        updateFreqList(mpKeyAddr[key]);//as this node has been accessed hence update the frequency list
        return retVal;
    }
    
    void put(int key, int value) {
        if(capacity==0) return;
        
        if(mpKeyAddr.find(key)!=mpKeyAddr.end())//node is in the cache
        {
            mpKeyAddr[key]->value = value;
            updateFreqList(mpKeyAddr[key]);
        }
        else//node is not in the cache
        {
           if(currSize==capacity)
           {
               Node *nodeToBeDel = mpFreqList[minFreq]->head->next;//As elements were added at rear end hence least recently
               														//element with minimum frequecy will be at the begining
               														//of the list for frequency = minFreq
			   mpFreqList[minFreq]->delNode(nodeToBeDel);		//delete that node with minimum frequency and least recently used
               mpKeyAddr.erase(nodeToBeDel->key);				//remove that node from mpKeyAddr map also
               currSize--;//deleting the above node decreases current occupancy of the cache by 1
           }
           minFreq = 1;//this element is going to be inserted for the first time hence it will cause minFreq = 1
           Node *newNode = new Node(key,value);
           List *newList = new List();
           if(mpFreqList.find(minFreq) != mpFreqList.end())//if a list with this freq is already existing then initialise this with it
               newList = mpFreqList[minFreq];
           newList->addNodeRear(newNode);//add new node to the rear end of that list
           mpFreqList[minFreq] = newList;//update the list for that frequency with the new updated list
           mpKeyAddr[key] = newNode;//save the newNode address in the mpKeyAddr map
           currSize++;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
