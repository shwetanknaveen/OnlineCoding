//Problem link - https://leetcode.com/problems/isomorphic-strings/

//We need to check that whether there is one to one mapping or not in order and the mapping should be bijective

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mp,mpRev;
        if(s.length() != t.length()) return false;
        
        for(int i=0;i<s.length();i++)
        {
            if(mp.count(s[i])==0)//no mapping from s to t
            {
                if(mpRev.count(t[i])==0)//no reverse mapping from t to s also
                {
                    mp[s[i]] = t[i];//set both the mappings
                    mpRev[t[i]] = s[i];
                }
                else if(mpRev[t[i]] != s[i]) return false;//there is reverse mapping which is not mapped to current character
                else mp[s[i]] = t[i];//there is reverse mapping then just set this forward mapping
            }
            else//mapping already exist from s to t
            {
                if(mp[s[i]] != t[i]) return false;
            }
        }
        return true;
    }
};
