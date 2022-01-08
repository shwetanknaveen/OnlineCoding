//Problem link - https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1/
//Video link - https://www.youtube.com/watch?v=9h10fqkI7Nk&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=37

//Variation of Matrix Chain Multiplication
class Solution{
public:
    bool isPalindrome(string &s,int i,int j)
    {
        while(i<j)
        {
            if(s[i++] != s[j--])
            return false;
        }
        return true;
    }
    int solve(string &s,int i,int j,vector<vector<int>> &dp)
    {
        if(i>=j) return 0;//if string is of lenght<=1 then no partition is required to make it palindrome
        if(isPalindrome(s,i,j)) return 0;//if string from i to j is already palindrome then no partition is required
        
        if(dp[i][j] != -1) return dp[i][j];
        
        dp[i][j] = INT_MAX;
        int leftSubProb,rightSubProb;
        /*
		Decide how the partition between i to j will happen with help of k
		Here we have to group-> indices from i to k and k+1 to j. So we see here that we can't take k to j as when 
		k reaches j, k+1 will throw error        
        */
        for(int k=i;k<j;k++)
        {
            //dp[i][j] = min(dp[i][j],1+solve(s,i,k,dp)+solve(s,k+1,j,dp));	//see more optimised version below->Check dp matrix before making recursive call
            if(dp[i][k] != -1)
            leftSubProb = dp[i][k];
            else
            leftSubProb = solve(s,i,k,dp);
            
            if(dp[k+1][j] != -1)
            rightSubProb = dp[k+1][j];
            else
            rightSubProb = solve(s,k+1,j,dp);
            dp[i][j] = min(dp[i][j],1+leftSubProb+rightSubProb);
        }
        return dp[i][j];
    }
    int palindromicPartition(string str)
    {
        int n=str.length();
        int i=0;
        int j=n-1;
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(str,i,j,dp);
    }
};

