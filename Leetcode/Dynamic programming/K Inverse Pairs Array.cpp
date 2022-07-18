//Problem link - https://leetcode.com/problems/k-inverse-pairs-array/

class Solution {
public:
    int mod = 1e9 + 7;
    int solve(int n,int k,vector<vector<int>> &dp)//this function for top down approach
    {
        if(k==0) return 1;//If no inverse pair is needed then all elements have to be in ascending order
        if(k<0) return 0;//No possibility with negative number of inverse pairs
        
        if(dp[n][k] != -1) return dp[n][k];
        
        int ans = 0;
        //Actually loop should run from 0 to min(k,n-1)
        for(int i=0;i<n;i++)
        {
            ans = (ans + solve(n-1,k-i,dp))%mod;
            /*
            If we take out the smallest from n numbers and fix it on the first place, then it won't
            form any inverse pair hence we will have to search for k inverse pairs in (n-1) numbers 
            again. Similarily if we choose second smallest number from n numbers and fix it on the
            first place, then it will surely form one inverse pair with the smallest number hence
            we need to search k-1 inverse pairs in n-1 numbers.
            If we choose largest number from n numbers and fix on first place then it will form
            inverse pair with rest of n-1 numbers and hence we need to search k-(n-1) inverse pairs
            in n-1 numbers
            */
        }
        return dp[n][k] = ans;
    }
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n+1,vector<int>(k+1,0));
        
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=k;j++)
            {
                if(j==0) dp[i][j] = 1;//No inverse pair needed as j=0
                else
                {
                    // for(int k=0;k<=min(j,i-1);k++)   //Rather than calculating each time, let's do cummulative sum
                        // dp[i][j] = (dp[i][j] + dp[i-1][j-k])%mod;
                    int val = (dp[i - 1][j] + mod - ((j - i) >= 0 ? dp[i - 1][j - i] : 0)) % mod;
                    dp[i][j] = (dp[i][j - 1] + val) % mod;
                }
            }
        }
        return ((dp[n][k] + mod - (k > 0 ? dp[n][k - 1] : 0)) % mod);
        
        
        //return solve(n,k,dp); //When dp is initialized with -1 for top down approach
    }
};
