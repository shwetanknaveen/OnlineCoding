//Problem link - https://leetcode.com/problems/contains-duplicate/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> allNums;
        for(int i:nums)
        {
            if(allNums.find(i) == allNums.end())
                allNums.insert(i);
            else return true;
        }
        return false;
    }
};
