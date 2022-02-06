//Problem link - https://leetcode.com/problems/valid-anagram/

//Approach 1 -> Using map
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mp;
        for(char c:s)
            mp[c]++;
        for(char c:t)
            mp[c]--;
        for(auto p:mp)
        {
            if(p.second!=0)
                return false;
        }
        return true;
    }
};

//Approach 2-> Using vector as hash

class Solution {
public:
    bool isAnagram(string s, string t) {
        int lenS = s.length(),lenT = t.length();
        vector<int> hash(256,0);//fill all values with 0	=>There are 256 characters
        
        if(lenS != lenT) return false;
        
        for(int i=0;i<lenS;i++)
        {
            hash[s[i]]++;
            hash[t[i]]--;
        }
        for(int i:hash)
        {
            if(i!=0)
                return false;
        }
        return true;
            
    }
};
