//Problem link - https://leetcode.com/problems/russian-doll-envelopes/
//Related question - "Striver 180/LIS"
//Video link - https://www.youtube.com/watch?v=3fF1r5nhQX4
//Self video explanation -> https://www.youtube.com/watch?v=m4XY1Pths3U&list=PLudlC33BR8eEiSWH654z2GKEF3Ckz6QWB&index=8
//Approach 1-> Giving TLE -> Similar to how we solved LIS
class Solution {
public:
    int helper(vector<vector<int>> &env,vector<vector<int>> &dp,int ind,int lastInd)
    {
        int nEnv = env.size();
        if(ind>= nEnv) return 0;
        if(dp[ind][lastInd] != 0) return dp[ind][lastInd];
        
        if(env[ind][0]>env[lastInd][0] && env[ind][1]>env[lastInd][1])
        {
            dp[ind][lastInd] = max(1+helper(env,dp,ind+1,ind),helper(env,dp,ind+1,lastInd));
        }
        else
        {
            dp[ind][lastInd] = helper(env,dp,ind+1,lastInd);
        }
        return dp[ind][lastInd];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end());
        envelopes.insert(envelopes.begin(),{0,0});
        int n = envelopes.size();
        vector<vector<int>> dp(n,vector<int>(n));
        return helper(envelopes,dp,1,0);
    }
};

//Approach 2-> Using LIS concept
class Solution {
public:
    static bool cmp(vector<int> &e1,vector<int> &e2)
    {
        return e1[0]<e2[0] || (e1[0]==e2[0] && e1[1]>e2[1]);//if width is same then sort height in descending order so that both don't participate
        													//in LIS of height
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),cmp);
        vector<int> LISOfHeight;
        for(auto env : envelopes)
        {
            auto itr = lower_bound(LISOfHeight.begin(),LISOfHeight.end(),env[1]);
            if(itr==LISOfHeight.end()) LISOfHeight.push_back(env[1]);
            else *itr = env[1];
        }
        return LISOfHeight.size();
    }
};


//Trying to convert approach 1 top down code into bottom up using striver's logic

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) 
    {
        sort(envelopes.begin(),envelopes.end());
        envelopes.insert(envelopes.begin(),{0,0});
        int n = envelopes.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1));
        for(int ind = n-1;ind>=1;ind--)
        {
            for(int lastInd = n-1;lastInd>=0;lastInd--)
            {
                if(envelopes[ind][0]>envelopes[lastInd][0] && envelopes[ind][1]>envelopes[lastInd][1])//flip < to > because here it is checked in opposite direction
                {
                    dp[ind][lastInd] = max(1+dp[ind+1][ind],dp[ind+1][lastInd]);
                }
                else
                {
                    dp[ind][lastInd] = dp[ind+1][lastInd];
                }
            }
        }
        return dp[1][0];
    }
};
