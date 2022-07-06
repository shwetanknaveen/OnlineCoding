//Problem link - https://leetcode.com/problems/decode-the-message/

class Solution {
public:
    string decodeMessage(string key, string message) {
        char encode = 'a';
        unordered_map<char,char> mp;
        mp[' '] = ' ';
        for(char c:key)
        {
            if(c==' '  || mp.find(c) != mp.end()) continue;
            mp[c] = encode++;
        }
        string ans = "";
        for(char c: message)
        {
            ans += mp[c];
        }
        return ans;
    }
};
