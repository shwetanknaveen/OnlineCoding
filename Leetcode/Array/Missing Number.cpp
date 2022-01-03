//Problem link - https://leetcode.com/problems/missing-number/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = 0;//exor with 0 is identity
        int n = nums.size();//n size numbers can have distinct n-1 numbers in range [0,n]
        
		for(int i=0;i<=n;i++)
            ans ^= i;//exor of all the numbers from 0 to n
        for(int i:nums)
            ans ^= i;//when exor'ed with all the array numbers, existing number will cancel out and only that will remain
            		//which is missing from the array
        return ans;
    }
};
