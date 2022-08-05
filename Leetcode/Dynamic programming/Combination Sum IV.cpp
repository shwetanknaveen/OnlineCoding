//Problem link - https://leetcode.com/problems/combination-sum-iv/
//See "Leetcode/Dynamic Programming/Coing Change 2" for similar concept
class Solution {
public:
    int solve(vector<int> &nums,int target,int ind,vector<vector<int>> &dp)
    {
        if(target<=0 || ind>=nums.size())
        {
            return target==0;//We can't proceed further hence if we have target = 0 then this is one permutation
        }
        if(dp[ind][target] != -1) return dp[ind][target];
        
        int take = solve(nums,target-nums[ind],0,dp);//Since here we are dealing with permutations hence when we take this,
        											//we can again start from 0 index and start looking that we can take what
        int skip = solve(nums,target,ind+1,dp);
        
        return dp[ind][target] = take+skip;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size(),vector<int>(target+1,-1));
        return solve(nums,target,0,dp);
    }
};



//Since permutation won't depend on the index hence we can reduce the dimension of dp to 1

class Solution {
public:
    int solve(vector<int> &nums,int target,int ind,vector<int> &dp)
    {
        if(target<=0 || ind>=nums.size())
        {
            return target==0;
        }
        if(dp[target] != -1) return dp[target];
        
        int take = solve(nums,target-nums[ind],0,dp);
        int skip = solve(nums,target,ind+1,dp);
        
        return dp[target] = take+skip;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1,-1);
        return solve(nums,target,0,dp);
    }
};
