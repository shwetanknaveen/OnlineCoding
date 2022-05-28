//Problem link - https://leetcode.com/problems/check-if-number-has-equal-digit-count-and-digit-value/

class Solution {
public:
    bool digitCount(string num) {
        vector<int> mp(10,0);
        for(char c:num)
            mp[c-'0']++;
        for(int i=0;i<num.length();i++)
        {
            if(mp[i] != (num[i]-'0')) return false;
        }
        return true;
    }
};
