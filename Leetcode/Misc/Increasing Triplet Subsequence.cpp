//Problem link - https://leetcode.com/problems/increasing-triplet-subsequence/

//Approach 1-> Using linear space
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        int mini = nums[0],maxi = nums[n-1];
        for(int i=1;i<n-1;i++)
        {
            if(nums[i]>mini) ans[i]++;//there is a number on left of this number which is smaller than this number
            mini = min(mini,nums[i]);
        }
        for(int i=n-2;i>=1;i--)
        {
            if(nums[i]<maxi) ans[i]++;//there is a number on right of this number which is larger than this number
            maxi = max(maxi,nums[i]);
        }
        for(int i:ans) if(i==2) return true;//there is a smaller number on left and larger number on right of number at this index
        return false;
    }
};

//Approach 2-> See Longest increasing subsequence problem
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> LIS;
        for(int i:nums)
        {
            auto ind = lower_bound(LIS.begin(),LIS.end(),i);
            if(ind==LIS.end())
            {
                LIS.push_back(i);
                if(LIS.size()==3) return true;
            }
            else
                *ind = i;
        }
        return false;
    }
};
