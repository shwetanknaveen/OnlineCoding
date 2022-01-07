//Problem link - https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1
//Video link - https://www.youtube.com/watch?v=-fx6aDxcWyg&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=25

//This is just a varaition of LCS
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
	int minOperations(string str1, string str2) 
	{ 
	    vector<vector<int>> dp(str1.length()+1,vector<int>(str2.length()+1,-1));
	    int lcs = LCS(str1,str2,0,0,dp);
	    return (str1.length()+str2.length()-2*lcs);
	    //Minimum number of deletions required to convert str1 into str2 = str1.length() - lcs
	    //Minimum number of insertion required to convert str1 into str2 = str2.length() - lcs
	    
	} 
};
