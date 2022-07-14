//Problem link - https://leetcode.com/problems/largest-number/

class Solution {
public:
    static bool cmp(string &num1,string &num2)
    {
        if((num1+num2).compare(num2+num1)>=0) return true;
        return false;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> allNums;
        bool allZero = true;
        for(int i:nums)
        {
            if(i>0) allZero = false;
            allNums.push_back(to_string(i));
        }
        if(allZero) return "0";
        string ans;
        sort(allNums.begin(),allNums.end(),cmp);
        for(string &s:allNums)
            ans += s;
        return ans;
    }
};
