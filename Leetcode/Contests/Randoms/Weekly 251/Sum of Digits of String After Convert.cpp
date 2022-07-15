//Problem link - https://leetcode.com/problems/sum-of-digits-of-string-after-convert/
class Solution {
public:
    int getDigSum(int n)
    {
        int ans = 0;
        while(n)
        {
            ans += n%10;
            n /= 10;
        }
        return ans;
    }
    int getLucky(string s, int k) {
        vector<int> nums;
        for(char c:s)
            nums.push_back(c-'a'+1);
        
        k--;//k>=1 hence let's initialise ans after first transform and reduce k by 1
        int ans = 0;
        for(int i:nums)
            ans += getDigSum(i);
      
        while(k--)
            ans = getDigSum(ans);
        return ans;
    }
};
