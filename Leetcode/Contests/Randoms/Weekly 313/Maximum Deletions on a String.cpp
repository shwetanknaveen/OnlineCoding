//Problem link - https://leetcode.com/problems/maximum-deletions-on-a-string/
class Solution {
public:
    int solve(string &s,int i,vector<int> &dp)//i means from which index we are considering the start
    {
        if (dp[i] == 0) 
        {
            dp[i] = 1;
            for (int len = 1; i + 2 * len <= s.size(); ++len)
                if (s.compare(i, len, s, i + len, len) == 0)
                //if((s.substr(i,len)).compare(s.substr(i+len,len))==0)
                    dp[i] = max(dp[i], 1 + solve(s, i + len,dp));
        }
        return dp[i];
    }
    int deleteString(string &s) 
    {
        vector<int> dp(s.size()+1,0);
        return solve(s,0,dp);
    }
};
