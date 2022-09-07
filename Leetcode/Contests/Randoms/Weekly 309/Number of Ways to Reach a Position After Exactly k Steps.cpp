//Problem link - https://leetcode.com/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps/

class Solution {
public:
    int mod = 1e9 + 7;
    int startPos,endPos;
    vector<vector<int>> dp;
    int solve(int pos,int k)
    {
        if(k==0) return pos==endPos;//if taken k steps and reached endPos then this is one way
        
        if(dp[pos+1000][k] != -1) return dp[pos+1000][k];//Since position may be negative hence we shift on positive side by 
        												//adding 1000
        
        return dp[pos+1000][k] = (solve(pos-1,k-1) + solve(pos+1,k-1))%mod;//Once go left then go right
    }
    int numberOfWays(int startPos, int endPos, int k) 
    {
        this->startPos = startPos;
        this->endPos = endPos;
        dp.resize(3000,vector<int>(k+1,-1));//Since we will shift for positive side hence we keep first dimension as 3000
        return solve(startPos,k);
    }
};
