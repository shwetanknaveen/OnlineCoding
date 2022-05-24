//Problem link - https://leetcode.com/problems/first-unique-character-in-a-string/

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> mp;
        for(char c:s)
            mp[c]++;
        for(int i=0;i<s.length();i++)
        {
            if(mp[s[i]]==1) return i;
        }
        return -1;
    }
};

//More optimisation with using vector rather than map
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> mp(26,0);
        for(char c:s)
            mp[c-'a']++;
        for(int i=0;i<s.length();i++)
        {
            if(mp[s[i]-'a']==1) return i;
        }
        return -1;
    }
};
