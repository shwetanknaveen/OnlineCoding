//Problem link - https://practice.geeksforgeeks.org/problems/rod-cutting0840/1/#
//Video link - https://www.youtube.com/watch?v=SZqAQLjDsag&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=14

//It's a variation of unbounded knapsack.
class Solution{
  public:
  int knapSack(int price[],int n,vector<vector<int>> &dp,int ind,int W)
  {
      if(ind>=n || W==0) return 0;
      if(dp[ind][W] != -1) return dp[ind][W];
      
      if(W>=(ind+1))//at index ind in price array, length of rod is ind+1. E.g., at first index length is 1 and ind is 0
      dp[ind][W] = 	max(price[ind]+knapSack(price,n,dp,ind,W-(ind+1)),          knapSack(price,n,dp,ind+1,W));
      				/*
					  Cut this piece of length (ind+1) and now remaining		We don't cut rod length of (ind+1)
					  rod length is W-(ind+1). We don't increase ind here
					  as we can cut same rod length again in remaining rod
					  */
	  else
      dp[ind][W] = knapSack(price,n,dp,ind+1,W);//if remaining rod length is less than prospective cut piece i.e., (ind+1)
      											//then obviously we have no other option but to skip
      
      return dp[ind][W];
  }
    int cutRod(int price[], int n) {
        int W = n;
        vector<vector<int>> dp(n+1,vector<int>(W+1,-1));
        return knapSack(price,n,dp,0,W);
    }
};
