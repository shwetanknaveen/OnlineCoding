//Question Link - https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
//Aditya verma link -Recursive prog- https://www.youtube.com/watch?v=kvyShbFVaY8&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=3
//Aditya verma memoization - https://www.youtube.com/watch?v=fJbIuhs24zQ&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=4
class Solution
{
    public:
    int knapSack(int W, int wt[], int val[], int n) 
    { 
    vector<vector<int>> dp(n+1,vector<int>(W+1,-1));
    return knapSackRec(W, wt, val, n, dp);
    }
    int knapSackRec(int W,int wt[],int val[],int n,vector<vector<int>> &dp)
    {
        if(n==0 || W==0)
        return 0;//if no elements are there to consider or remaining capacity of knapsack is 0 then we can get only 0 profit
        if(dp[n][W]!=-1) 
        return dp[n][W];//return already remembered value
        
		if(W>=wt[n-1])//when remaining capacity of bag is greater than weight of current element
					//n-1 for wt array is used because indexing is from 0 there
        {
            dp[n][W] = max(val[n-1]+knapSackRec((W-wt[n-1]),wt,val,n-1,dp)	,		knapSackRec(W,wt,val,n-1,dp));
            			/*take the element element and add its profit				Don't take the element and leave
							and reduce the remaining capacity of knapsack 			the knapsack capacity as it is*/		
            return dp[n][W];
        }
        else if(W<wt[n-1])//if current element is heavier then we can't take it
        {
            dp[n][W] = knapSackRec(W,wt,val,n-1,dp);
            return dp[n][W];
        }
    }
};

//Above code with using index variable ind

class Solution
{
    public:
    int knapSackHelp(int W,int wt[],int val[],int n,int ind,vector<vector<int>> &dp)
    {
        if(W==0 || ind>=n) return 0;//if ind>=N, it means that we are exploring outside given array
        
        if(dp[ind][W] != -1) return dp[ind][W];
        
        if(W>=wt[ind])
        dp[ind][W] = max(val[ind] + knapSackHelp(W-wt[ind],wt,val,n,ind+1,dp),
                                    knapSackHelp(W,wt,val,n,ind+1,dp));
        else
        dp[ind][W] = knapSackHelp(W,wt,val,n,ind+1,dp);
        
        return dp[ind][W];
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       vector<vector<int>> dp(n+1,vector<int>(W+1,-1));
       return knapSackHelp(W,wt,val,n,0,dp);//initially we start exploring from the first index hence ind=0
    }
};
