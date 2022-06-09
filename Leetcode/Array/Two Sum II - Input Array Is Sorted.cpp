//Project Link - https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int thisSum;
        for(int i=0,j=numbers.size()-1;i<j;)
        {
            thisSum = numbers[i]+numbers[j];
            if(thisSum==target) return {i+1,j+1};
            thisSum<target?i++:j--;
        }
        return {};
    }
};
