//Problem link - https://leetcode.com/problems/replace-elements-in-an-array/

class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++)
            mp[nums[i]] = i;
        
        for(auto v : operations)
        {
            int ind = mp[v[0]];
            nums[ind] = v[1];//Put the new number at the index
            mp[v[1]] = ind;//Save the index of the new number
            mp.erase(v[0]);
        }
        return nums;
            
    }
};
