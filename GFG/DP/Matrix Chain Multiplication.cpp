//Problem link - https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1/
//Video link - https://www.youtube.com/watch?v=kMK148J9qEE&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=33


/*
dp[i][j] represents cost of multiplying matrices from ith number to jth number

STEP -1 -> Identify right initial values of i and j
STEP -2 -> Write the base condition appropriately
STEP -3 -> Decide how the partition between i to j will happen with help of k
	`		Here we have to group-> matrices from i to k and k+1 to j. So we see here that we can't take k to j as when 
			k reaches j, k+1 will throw error
*/
class Solution{
public:
    int solve(int arr[],int i,int j,vector<vector<int>> &dp)
    {
        if(i>=j) return 0;//i>=j means we have only one matrix or we have no matrix in order to multiply
        if(dp[i][j] != -1) return dp[i][j];
        
        dp[i][j] = INT_MAX;
        for(int k=i;k<j;k++)
        {
            dp[i][j] = min(dp[i][j],solve(arr,i,k,dp)	+	solve(arr,k+1,j,dp)	+	arr[i-1]*arr[k]*arr[j]);
            					/*cost of multiplying		cost of multiplying 	cost of multiplying these groups
            						matrices from ith 		matrices from (k+1)th	first dimension of ith matrix is
            						to kth number			to jth number			arr[i-1], first dimension of (k+1)th
            																		matrix which is common dimension in both
            																		the groups is arr[k+1-1] = arr[k].
            																		The second dimesnsion of jth matrix is
            																		arr[j-1+1] = arr[j]
            					*/
        }
        return dp[i][j];
    }
    int matrixMultiplication(int N, int arr[])
    {
        int i=1,j=N-1;
        vector<vector<int>> dp(N+1,vector<int>(N+1,-1));
        return solve(arr,i,j,dp);
        
    }
};

