//Problem link - https://leetcode.com/problems/insert-delete-getrandom-o1/

class RandomizedSet {
public:
    map<int,int> mp;
    vector<int> nums;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val)!=mp.end()) return false;
        nums.push_back(val);
        mp.insert({val,nums.size()-1});
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val)==mp.end()) return false;
        
        //We can't simply erase from the nums vector because it will change actual index of other values
        //hence we swap the val to last of nums and update the index of last value and then delete the 
        //val from nums from end
        int last = nums[nums.size()-1];// = nums.back()
        swap(nums[nums.size()-1],nums[mp[val]]);
        mp[last] = mp[val];
        mp.erase(val);
        nums.pop_back();
        return true;
    }
    
    int getRandom() {
        int ind = rand()%nums.size();
        return nums[ind];
    }
};

