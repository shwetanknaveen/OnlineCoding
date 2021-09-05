//Problem link - https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1
//Aditya verma link - https://www.youtube.com/watch?v=aycn9KO8_Ls&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=13
class Solution
{
    public:
    int knapSack(int W, int wt[], int val[], int n) 
    { 
    vector<vector<int>> dp(n+1,vector<int>(W+1));
    for (int i = 0; i < n+1; i++)
        for (int j = 0; j < W + 1; j++)
            dp[i][j] = -1;
    return UnboundknapSackRec(W, wt, val, n, dp);
    }
    int UnboundknapSackRec(int W,int wt[],int val[],int n,vector<vector<int>> &dp)
    {
        if(n==0 || W==0)
        return 0;//if no elements are there to consider or remaining capacity of knapsack is 0 then we can get only 0 profit
        if(dp[n][W]!=-1) 
        return dp[n][W];//return already remembered value
        
		if(W>=wt[n-1])//when remaining capacity of bag is greater than weight of current element
					//n-1 for wt array is used because indexing is from 0 there
        {
            dp[n][W] = max(val[n-1]+UnboundknapSackRec((W-wt[n-1]),wt,val,n,dp)	,		UnboundknapSackRec(W,wt,val,n-1,dp));
            			/*take the element element and add its profit				Don't take the element and leave
							and reduce the remaining capacity of knapsack 			the knapsack capacity as it is
							Here lies the point of DIFFERENCE in unbound 
							knapsack. When we take the element we don't 
							remove it from further considerations and
							thus we call UnboundknapSackRec with 'n' again
							*/		
							
            return dp[n][W];
        }
        else if(W<wt[n-1])//if current element is heavier then we can't take it
        {
            dp[n][W] = UnboundknapSackRec(W,wt,val,n-1,dp);
            return dp[n][W];
        }
    }
};

