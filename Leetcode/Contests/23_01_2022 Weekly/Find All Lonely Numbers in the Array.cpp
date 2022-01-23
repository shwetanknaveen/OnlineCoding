//Problem link - https://leetcode.com/problems/find-all-lonely-numbers-in-the-array/

class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        map<int,int> mp;
        vector<int> ans;
        for(int i:nums)
            mp[i]++;
        for(int i:nums)
        {
            if(mp[i] == 1 && mp.find(i-1) == mp.end() && mp.find(i+1) == mp.end())
                ans.push_back(i);
        }
        return ans;
    }
};
