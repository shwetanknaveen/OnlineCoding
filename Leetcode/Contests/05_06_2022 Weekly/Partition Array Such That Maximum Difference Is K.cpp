//Problem link - https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k/

class Solution 
{
public:
    int partitionArray(vector<int>& nums, int k) 
    {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int i=0,j=0,ans = 0;
        while(i<n && j<n)
        {
            for(j = i;j<n && nums[i]+k>=nums[j];j++);//from i to j, elements are taken in one set
            i=j;
            ans++;
        }
        return ans;
    }
};
