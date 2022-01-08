//Problem link - https://practice.geeksforgeeks.org/problems/form-a-palindrome1455/1/#
//Video link - https://www.youtube.com/watch?v=AEcRW4ylm_c&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=31

//Note-> Minimum number of deletions required in a string to make it a palindrome is same as minimum number of insertions
//required to make it a palindrome

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
    int countMin(string str){
    string strRev = str;
    int n = str.length();
    reverse(strRev.begin(),strRev.end());
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    int palinLength = LCS(str,strRev,0,0,dp);
    return (n-palinLength);
    }
};
