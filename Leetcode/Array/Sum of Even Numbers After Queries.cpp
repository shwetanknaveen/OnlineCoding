//Problem link - https://leetcode.com/problems/sum-of-even-numbers-after-queries/

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) 
    {
        int evenSum = 0;
        for(int i:nums)
            if(!(i&1)) evenSum += i;
        vector<int> ans;
        for(auto query:queries)
        {
            int oldVal = nums[query[1]];
            nums[query[1]] += query[0];
            if(!(oldVal&1))//if it was previously even
                evenSum -= oldVal;
            if(!(nums[query[1]]&1))//if new val is even
                evenSum += nums[query[1]];
            
            ans.push_back(evenSum);
        }
        return ans;
    }
};
