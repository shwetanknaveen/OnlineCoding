//Problem link - https://leetcode.com/problems/subsets/

class Solution {
public:
    void solve(int ind,vector<int> &nums,vector<int> &temp,vector<vector<int>> &ans)
    {
        if(ind>=nums.size())
        {
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[ind]);
        solve(ind+1,nums,temp,ans);
        temp.pop_back();
        solve(ind+1,nums,temp,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0,nums,temp,ans);
        return ans;
    }
};
