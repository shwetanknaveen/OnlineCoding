//Problem link - https://leetcode.com/problems/number-of-zero-filled-subarrays/
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        for(int i=0,j=0;i<n && j<n;)
        {
            while(j<n && nums[j]==0) j++;
            int size = j-i;
            for(int setSize = 1;setSize<=size;setSize++)
            {
                ans += size - setSize + 1;
            }
            j++;
            i = j;
        }
        return ans;
    }
};
