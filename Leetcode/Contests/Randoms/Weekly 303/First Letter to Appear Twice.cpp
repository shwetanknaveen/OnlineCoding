//Problem link - https://leetcode.com/problems/first-letter-to-appear-twice/

class Solution {
public:
    char repeatedCharacter(string s) {
        vector<int> mp(26,0);
        for(char c:s)
        {
            if(mp[c-'a']) return c;
            mp[c-'a'] = true;
        }
        return 'a';
    }
};
