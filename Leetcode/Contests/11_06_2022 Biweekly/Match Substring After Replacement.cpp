//Problem link - https://leetcode.com/problems/match-substring-after-replacement/

class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        unordered_map<char,unordered_set<char>> mp;
        for(auto v:mappings)
            mp[v[0]].insert(v[1]);
        
        int sLen = s.length(), subLen = sub.length();
        for(int i=0;i<=sLen-subLen;i++)//Window in s starts from ith index
        {
            bool flag = true;
            for(int j=0;j<subLen;j++)
            {
                if(s[i+j]==sub[j]) continue;//Character already match in sub character hence no need of replacement
                if(mp.find(sub[j])==mp.end())//No mapping exist to change replace the unmatching character
                {
                    flag = false;
                    break;
                }
                if(mp[sub[j]].find(s[i+j])==mp[sub[j]].end())//There is mapping to replace the character but required character is not there
                {											//for replacement
                    flag = false;
                    break;
                }
            }
            if(flag) return true;
        }
        return false;
    }
};
