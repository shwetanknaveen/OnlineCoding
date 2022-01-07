//Problem link - https://practice.geeksforgeeks.org/problems/longest-palindromic-subsequence-1612327878/1/
//Video link - https://www.youtube.com/watch?v=wuOOOATz_IA&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=26

//This is just a variation of LCS
//Longest palindromic subsequence in a string str is LCS in str and reverse of str

class Solution{
  public:
  int LCS(string &x,string &y,int ind1,int ind2,vector<vector<int>> &dp)
	{
	    if(ind1>=x.length() || ind2>=y.length()) return 0;
	    
	    if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
	    
	    if(x[ind1] == y[ind2])
	    dp[ind1][ind2] = 1 + LCS(x,y,ind1+1,ind2+1,dp);
	    
	    else
	    dp[ind1][ind2] = max(LCS(x,y,ind1+1,ind2,dp),LCS(x,y,ind1,ind2+1,dp));
	    
	    return dp[ind1][ind2];
	}
    int longestPalinSubseq(string A) {
        vector<vector<int>> dp(A.length()+1,vector<int>(A.length()+1,-1));//Obviously A and revA will have same length
        string revA = A;
        reverse(revA.begin(),revA.end());//revA is reverse of string A
        return LCS(A,revA,0,0,dp);
    }
};
