//Problem link - https://leetcode.com/problems/max-consecutive-ones/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = 0,left=0,right=0,n = nums.size();
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
            {
            left = i;
            while( i<n && nums[i]==1) i++;//lastly it will put i to such index which is 0 or out of bound hence if it's skipped
            							//it doesn't affect the answer
            right = i-1;
            maxi = max(maxi,right-left+1);
            }
        }
        return maxi;
    }
};
