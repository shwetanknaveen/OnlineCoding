//Problem link - https://leetcode.com/problems/longest-common-subsequence/
//Video link - https://www.youtube.com/watch?v=hR3s9rGlMTU&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=21

class Solution {
public:
	/*
	dp[i][j] is the length of longest common subsequence in string A from index 0 to i and string B from index 0 to j
	*/
    int LCS(string &A,string &B,int &l1,int &l2,int ind1,int ind2,vector<vector<int>> &dp)
    //passing string A and B not as reference thrown TLE since it had to be copied many time
    {
        if(ind1>=l1 || ind2>=l2) return 0;//if we are searching outside the strings then there can't be common subsequence
        
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        
        if(A[ind1] == B[ind2]) 
        dp[ind1][ind2] = (1 + LCS(A,B,l1,l2,ind1+1,ind2+1,dp));//if this character is same in both the strings then count this
        														//character in common part and count the common subsequence in remaining 
        														//part
        
        else 
        dp[ind1][ind2] = max(LCS(A,B,l1,l2,ind1+1,ind2,dp),LCS(A,B,l1,l2,ind1,ind2+1,dp));
        				//if current character is not same then we can skip this character from either of string
        
        return dp[ind1][ind2];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int l1=text1.length(), l2=text2.length();
        vector<vector<int>> dp(l1+1,vector<int>(l2+1,-1));
        return LCS(text1,text2,l1,l2,0,0,dp);
    }
};
