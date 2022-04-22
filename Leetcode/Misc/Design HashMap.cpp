//Problem link - https://leetcode.com/problems/design-hashmap/

//See question "Leetcode/Misc/Design HashSet"

class MyHashMap {
public:
    vector<pair<int,int>> data[1000];

    void put(int key, int value) {
        bool found = false; 
        int bucket = key%1000;
        int siz = data[bucket].size();
        for(int i=0;i<siz;i++)
        {
            if(data[bucket][i].first==key)//if key is found already existing then update the already existing value mapped to the key
            {
                data[bucket][i].second = value;
                found = true;
                break;
            }
        }
        if(!found)//if key doesn't exist in the data then insert new key,value pair in the respective bucket
            data[bucket].emplace_back(make_pair(key,value));
    }
    
    int get(int key) {
        int bucket = key%1000;
        for(pair<int,int> p:data[bucket])
        {
            if(p.first==key)
                return p.second;
        }
        return -1;
    }
    
    void remove(int key) {
        int bucket = key%1000;
        int siz = data[bucket].size();
        for(int i=0;i<siz;i++)
        {
            if(data[bucket][i].first==key)//if key is found existing in its respective bucket
            {
                swap(data[bucket][i],data[bucket][siz-1]);//then swap it with end of that bucket and then remove the last one so that we
                data[bucket].pop_back();				//don't have to use erase function()
                return;
            }
        }
    }
};

