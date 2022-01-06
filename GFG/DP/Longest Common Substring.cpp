//Problem link - https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1/#
//Video link -	https://www.youtube.com/watch?v=HrybPYpOvz0&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=22

/* IMPORTANT NOTE-
Here dp[i][j] means longest common substring between string A starting from index i and string B starting from index j*/
class Solution{
    public:
    int LCS(string &A,string &B,int &l1,int &l2,int ind1,int ind2,vector<vector<int>> &dp)
    //passing string A and B not as reference thrown TLE since it had to be copied many time
    {
        if(ind1>=l1 || ind2>=l2) return 0;//if we are searching outside the strings then there can't be common substring
        
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        
        if(A[ind1] == B[ind2]) 
        dp[ind1][ind2] = (1 + LCS(A,B,l1,l2,ind1+1,ind2+1,dp));//if this character is same in both the strings then count this
        														//character in common part and count the common subsequence in remaining 
        														//parts
        
        else 
        dp[ind1][ind2] = 0;//if we get a mismatch here then our common substring streak is broken and hence we have to 
        					//reinitialize it to zero
        				
        
        return dp[ind1][ind2];
    }
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        int l1=S1.length(), l2=S2.length();
        vector<vector<int>> dp(l1+1,vector<int>(l2+1,-1));
        int ans=0;
        
        //Although we are calling LCS() here in nested loops, still its complexity will be O(n*m) as for the first time only
        //dp[i][j] will be calculated and for the rest of the times it will be returned in O(1) time
        
		for(int startIndStrA=0;startIndStrA<l1;startIndStrA++)//fix index in string A
        {
            for(int startIndStrB=0;startIndStrB<l2;startIndStrB++)//iterate over all index for starting index in string B
            {
                ans = max(ans,LCS(S1,S2,l1,l2,startIndStrA,startIndStrB,dp));
            }
        }
        return ans;
    }
};


