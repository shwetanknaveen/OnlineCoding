//Problem link - https://leetcode.com/problems/happy-number/
class Solution {
public:
    int getSquareSum(int n)
    {
        int ans = 0,dig;
        while(n)
        {
            dig = n%10;
            ans += dig*dig;
            n /= 10;
        }
        return ans;
    }
    bool isHappy(int n) {
        unordered_set<int> nums;
        nums.insert(n);
        while(n!=1)
        {
            int sqSum = getSquareSum(n);
            if(nums.find(sqSum)==nums.end())
            {
                nums.insert(sqSum);
                n = sqSum;
            }
            else
                return false;
        }
        return true;
    }
};
