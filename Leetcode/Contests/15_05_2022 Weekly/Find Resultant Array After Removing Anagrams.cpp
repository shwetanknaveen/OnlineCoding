//Problem link - https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/

class Solution {
public:
    bool isAnagram(string s1,string s2)
    {
        unordered_map<char,int> mp;
        for(char c:s1) mp[c]++;
        for(char c:s2) mp[c]--;
        
        for(auto itr=mp.begin();itr!=mp.end();itr++)
        {
            if(itr->second != 0) return false;
        }
        return true;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        for(string word:words)
        {
            if(ans.empty()) ans.push_back(word);
            else
            {
                if(isAnagram(word,ans[ans.size()-1]))
                    continue;
                ans.push_back(word);
            }
        }
        return ans;
    }
};
