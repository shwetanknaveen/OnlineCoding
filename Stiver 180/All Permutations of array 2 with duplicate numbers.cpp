//Problem link - https://leetcode.com/problems/permutations-ii/
//Video link - https://www.youtube.com/watch?v=is_T6uzlTyg

//Time complexity O(n! x n)
//Space complexity O(n^2)	-->Unordered set is at each level of recursion
class Solution {
public:
    void solve(vector<int> &nums,vector<vector<int>> &ans,int ind)
    {
        if(ind == nums.size())//if index is crossing the array boundary then push the current state of permutated numbers
        					//in the array to ans
        {
            ans.push_back(nums);
            return;
        }
        
        unordered_set<int> taken;//to ensure that swapping doesn't happen with same numbers
        for(int i=ind;i<nums.size();i++)//try swapping this number with every number ahead
        {
            if(taken.find(nums[i]) != taken.end())
                continue;
            taken.insert(nums[i]);
            swap(nums[i],nums[ind]);
            solve(nums,ans,ind+1);//recursively call the function from next index
            swap(nums[i],nums[ind]);//swap back to original state so that when recursion call returns to this level it can
            	`					//explore other possibilites
            	
        }
        
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(nums,ans,0);
        return ans;
    }
};

//We can check for duplicacy in following way too

class Solution {
public:
    void solve(vector<int> &nums,vector<vector<int>> &ans,int ind, map<vector<int>,bool> &is_vector_included)
    {
        if(ind == nums.size() && !is_vector_included[nums])
        {
            ans.push_back(nums);
            is_vector_included[nums] = true;
            return;
        }
        
        for(int i=ind;i<nums.size();i++)
        {
            swap(nums[i],nums[ind]);
            solve(nums,ans,ind+1,is_vector_included);
            swap(nums[i],nums[ind]);
            	
        }
        
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        map<vector<int>,bool> is_vector_included;
        solve(nums,ans,0,is_vector_included);
        return ans;
    }
};
