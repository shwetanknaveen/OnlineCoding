//Problem link - https://leetcode.com/problems/ones-and-zeroes/

class Solution {
public:
    int helper(vector<string> &strs,int ind,int m,int n,vector<vector<vector<int>>> &dp,vector<vector<int>> &store)
    {
        if(ind>=strs.size()) return 0;
        
        if(dp[ind][m][n] != -1) return dp[ind][m][n];
        
        
        if(m>=store[ind][0] && n>=store[ind][1])//it means this string at ind in strs can be either taken or not taken
        {
            dp[ind][m][n] = max(1+helper(strs,ind+1,m-store[ind][0],n-store[ind][1],dp,store),helper(strs,ind+1,m,n,dp,store));
            			/*
            				If it is taken then count of strings in subset increases by 1
            				and number of 0s and 1s allowed at max will now change. 
            			*/
        }
        else
        {
            dp[ind][m][n] = helper(strs,ind+1,m,n,dp,store);
        }
        
        return dp[ind][m][n];
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int nStrings = strs.size();
        vector<vector<int>> store(nStrings,vector<int>(2,0));
        
        //For each string, store number of 0s and 1s in it
        for(int i=0;i<nStrings;i++)
        {
            int ones = 0, zeroes = 0;
            for(int j=0;j<strs[i].size();j++)
            {
                if(strs[i][j]=='0')
                    zeroes++;
                else ones++;
            }
            //for ith string in strs, store[i][0] has number of 0s and store[i][1] has number of 1s in it
            store[i][0] = zeroes;
            store[i][1] = ones;
        }
        vector<vector<vector<int>>> dp(nStrings+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return helper(strs,0,m,n,dp,store);
    }
};
