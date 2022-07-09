//Problem link - https://leetcode.com/problems/maximum-difference-between-increasing-elements/

//Maximum difference will happen if we subtract least number on left side of present number from present number
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int mini = nums[0],maxDiff = INT_MIN;
        for(int i=1;i<nums.size();i++)
        {
            maxDiff = max(maxDiff,nums[i]-mini);
            mini = min(mini,nums[i]);
        }
        return maxDiff<=0?-1:maxDiff;
    }
};
