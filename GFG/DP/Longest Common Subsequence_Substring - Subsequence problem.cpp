//Problem link - https://practice.geeksforgeeks.org/problems/substring-subsequence-problem1631/1/#
//Variation of standard LCS - Longest Common Subsequence
class Solution {
  public:
    int LCS(string &A,string &B,int &l1,int &l2,int ind1,int ind2,vector<vector<int>> &dp)
    {
        if(ind1>=l1 || ind2>=l2) return 0;
        
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        
        if(A[ind1] == B[ind2]) 
        dp[ind1][ind2] = (1 + LCS(A,B,l1,l2,ind1+1,ind2+1,dp));
        
        else 
        dp[ind1][ind2] = LCS(A,B,l1,l2,ind1+1,ind2,dp);//We can skip this character as it is not matching from only String A 
														//since ind2 is starting index of substring B
        
        return dp[ind1][ind2];
    }
    int getLongestSubsequence(string A, string B) {
        int l1=A.length(), l2=B.length();
        vector<vector<int>> dp(l1+1,vector<int>(l2+1,-1));
        
        int ans=0;
        for(int startIndStrB=0;startIndStrB<l2;startIndStrB++)//since we can't skip characters in string B hence we check possibility by starting string B
        					//at its every index
        ans = max(ans,LCS(A,B,l1,l2,0,startIndStrB,dp));
        
        return ans;
    }
};
