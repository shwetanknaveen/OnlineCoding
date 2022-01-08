//Problem link - https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1#
//Video link - https://www.youtube.com/watch?v=hbTaCmQGqLg&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=29

class Solution {
	public:
	    int modifiedLCS(string &s1,string &s2,int ind1,int ind2,vector<vector<int>> &dp)
	    {
	        if(ind1 == s1.length() || ind2 == s2.length()) return 0;//if strings are starting after their end indices then
	        														//there can't be a common subsequence
	        
	        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
	        
	        if(s1[ind1] == s2[ind2] && ind1!=ind2)//only point of change from standard LCS that we check to ensure that 
	        										//two indices are not equal.If characters are matching and indices
	        										//are not equal then we count that character in longest common repeating
	        										//subsequence
	        dp[ind1][ind2] = 1+modifiedLCS(s1,s2,ind1+1,ind2+1,dp);
	        
	        else
	        dp[ind1][ind2] = max(modifiedLCS(s1,s2,ind1+1,ind2,dp),modifiedLCS(s1,s2,ind1,ind2+1,dp));
	        
	        return dp[ind1][ind2];
	    }
		int LongestRepeatingSubsequence(string str){
		    int l=str.length();
		    vector<vector<int>> dp(l+1,vector<int>(l+1,-1));
		    return modifiedLCS(str,str,0,0,dp);
		}

};

