//Problem link - https://leetcode.com/problems/get-maximum-in-generated-array/

class Solution {
public:
    
    int getMaximumGenerated(int n) {
        vector<int> nums(n+1,0);
        int ans = INT_MIN;
        for(int ind=0;ind<=n;ind++)
        {
            if(ind==0) nums[ind] = 0;
            else if(ind==1) nums[ind] = 1;
            else if(ind&1)
            {
                nums[ind] = nums[(ind-1)/2] + nums[(ind-1)/2 +1];
            }
            else
            {
             nums[ind] = nums[(ind)/2];   
            }
            ans = max(ans,nums[ind]);
        }
        return ans;
        
    }
};
