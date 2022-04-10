//Problem link - https://leetcode.com/problems/minimum-cost-to-cut-a-stick/
//Video link - https://www.youtube.com/watch?v=k0QaIqvHd8g&list=PLudlC33BR8eEiSWH654z2GKEF3Ckz6QWB&index=3
class Solution {
public:
    int solve(int cut_left,int cut_right,int rod_left,int rod_right,vector<int> &cuts,vector<vector<int>> &dp)
    {
        if(cut_left<0 || cut_right>=cuts.size() || cut_left>cut_right)
            return 0;//no possible cut hence no cost incured
        
        if(cut_left==cut_right)//this is the cut which has to be done now
            return (rod_right-rod_left);
        
        if(dp[cut_left][cut_right] != -1)
            return dp[cut_left][cut_right];
        
        int ans = INT_MAX;
        for(int cut_here=cut_left; cut_here<=cut_right; cut_here++)
        {
            ans = min(ans, (rod_right-rod_left)+solve(cut_left,cut_here-1,rod_left,cuts[cut_here],cuts,dp) 			+ 		solve(cut_here+1,cut_right,cuts[cut_here],rod_right,cuts,dp));
            										/*
            										For left part left index of cuts vector remains same					For right part, left index of cuts vector is immediate right of
            										and right part is immediate left of cut just done here					cut just done here i.e., cut_here+1. Left index of rod for right 
            										i.e., cut_here. Rod left remains same for the left cut part				cut part is cuts[cut_here] as we just cut rod from there and its
            										but it's right part will be the cut just done i.e., cuts[cut_here]		right part remains same.
            										*/
        }
        return dp[cut_left][cut_right] = ans;
    }
    int minCost(int n, vector<int>& cuts) {
        int nCuts = cuts.size();
        vector<vector<int>> dp(nCuts+1,vector<int>(nCuts,-1));
        sort(cuts.begin(),cuts.end());
        return solve(0,nCuts-1,0,n,cuts,dp);
    }
};
