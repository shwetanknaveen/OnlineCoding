//Problem link - https://leetcode.com/problems/design-hashset/

/*
We use open addressing here as collision handling technique.
Our hash function is key%1000
*/
class MyHashSet {
public:
    vector<int> data[1000];
    MyHashSet() {
        
    }
    
    void add(int key) {
        if(!contains(key))//to ensure that duplicate elements are not added up
            data[key%1000].emplace_back(key);
    }
    
    void remove(int key) {
        int bucket = key%1000;
        int siz = data[bucket].size();
        for(int i=0;i<siz;i++)
        {
            if(data[bucket][i]==key)//if key exists in the bucket then we swap it with last and then remove the last.Using erase() function is costly
            {
                swap(data[bucket][i],data[bucket][siz-1]);
                data[bucket].pop_back();
                return;
            }
        }
    }
    
    bool contains(int key) {
        int bucket = key%1000;
        for(int i:data[bucket])
        {
            if(i==key) return true;
        }
        return false;
    }
};

