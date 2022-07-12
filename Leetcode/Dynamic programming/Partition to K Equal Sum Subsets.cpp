//Problem link - https://leetcode.com/problems/partition-to-k-equal-sum-subsets/
//Video link - https://www.youtube.com/watch?v=OXZw4F_MYew
//See also "Leetcode/Recursion/Matchsticks to square"
//Approach 1- Recursion Approach => Gives TLE
class Solution {
public:
    bool solve(vector<int> &nums,vector<bool> &vis,int currSum,int &subsetSum,int k,int start)
    {
        if(k==1) return true;
        if(currSum==subsetSum)
            return solve(nums,vis,0,subsetSum,k-1,0);//for new subset, we have to again start exploring from first element in the nums
        
        for(int i=start;i<nums.size();i++)
        {
            if(vis[i] || currSum+nums[i]>subsetSum) continue;
            vis[i] = true;
            if(solve(nums,vis,currSum+nums[i],subsetSum,k,i+1)) return true;//for this subset, for other elements, we need not start to explore from start again so we start from (i+1) in nums
            vis[i] = false;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int totalSum = accumulate(nums.begin(),nums.end(),0);
        int n = nums.size();
        if(totalSum%k !=0 || k>n) return false;
        int subsetSum = totalSum/k;
        vector<bool> vis(n,false);
        return solve(nums,vis,0,subsetSum,k,0);
    }
};

//Approach 2 - Dynamic programing with bit manipulation
class Solution {
public:
    //There has to be k subsets each of sum subsetSum and the present sum of this subset is currSum
    //currSum will be dependent on mask
    bool solve(vector<int> &nums,int currSum,int &subsetSum,int k,int mask,unordered_map<int,int> &dp)
    {
        if(k<=1) return true;//take all the remaining elements and form k=1 subset hence possible
        int key = mask*20 + k;/*Since k can have 16 different values, hence this way we create a unique key because now each consecutive 
        value of mask will be 20 units far from each other and hence there won't be possiblity that (20 x mask + k) will be same for 
        different value of mask and k considering the fact that 1<=k<=16*/
        
        if(dp.find(key) != dp.end()) return dp[key];
        
        bool ans = false;
        for(int i=0;i<nums.size();i++)
        {
            if(!(mask&(1<<i)))//this element is not taken in this set yet
            {
                if(currSum+nums[i]==subsetSum)//taking this element will complete the current subset
                {
                    if(solve(nums,0,subsetSum,k-1,mask|(1<<i),dp))//include this element in the mask, reduce k by 1 as this subset is completed and put currSum = 0 for the new subset
                    {
                        ans = true;
                        break;
                    }
                }
                else if(currSum+nums[i]<subsetSum)//this element can be taken but taking this element won't complete the current subset hence we take this and look further
                {
                    if(solve(nums,currSum+nums[i],subsetSum,k,mask|(1<<i),dp))//We add this number in the currSum and include this number in the mask without changing the value of k
                    {
                        ans = true;
                        break;
                    }
                }
            }
        }
        return dp[key] = ans;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int totalSum = accumulate(nums.begin(),nums.end(),0);
        int n = nums.size();
        if(totalSum%k !=0 || k>n) return false;
        int subsetSum = totalSum/k;
        unordered_map<int,int> dp;
        return solve(nums,0,subsetSum,k,0,dp);//initially no element is taken hence mask and currSum is 0
    }
};


