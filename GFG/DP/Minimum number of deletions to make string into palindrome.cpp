//Problem link - https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions4610/1/
//Video link - https://www.youtube.com/watch?v=CFwCCNbRuLY&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=27

//This is just a variation of LCS
//Number of characters which have to be deleted to make the given string a palindrome, will be minimum when we make the 
//string into longest possible palindrome and we know that length of longest palindromic subsequence in a string is LCS of
//that string and its reverse

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
int minDeletions(string str, int n) { 
    string strRev = str;
    reverse(strRev.begin(),strRev.end());
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    int palinLength = LCS(str,strRev,0,0,dp);
    return (n-palinLength);
} 
