//Problem link - https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2,-1);
        int n = nums.size();
        auto firstIndItr = lower_bound(nums.begin(),nums.end(),target);
        int firstInd = firstIndItr - nums.begin();
        if(firstInd==n || nums[firstInd]>target) return ans;//target is not in nums
        ans[0] = ans[1] = firstInd;
        int secondInd = lower_bound(firstIndItr+1,nums.end(),target+1)-nums.begin();//looking for number just greater than target so that
        																			//if target exists for more than one time, its last 
        																			//occurence is just before target+1
        if(nums[secondInd-1]>target) return ans;//there is no second occrence of target
        ans[1] = secondInd-1;
        return ans;
    }
};
