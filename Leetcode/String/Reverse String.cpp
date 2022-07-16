//Problem link - https://leetcode.com/problems/reverse-string/

class Solution {
public:
    void reverseString(vector<char>& s) {
        int end = s.size()-1,start = 0;
        while(start<end)
            swap(s[start++],s[end--]);
    }
};
