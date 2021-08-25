//Question Link - https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
//Aditya verma link - https://www.youtube.com/watch?v=ntCGbPMeqgg&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=5
  //Bottom up approach
    int knapSack(int W, int wt[], int val[], int n)
    {
        vector<vector<int>> dp(n+1,vector<int>(W+1));
        for(int j=0;j<=W;j++)
        dp[0][j] = 0;//intialising first row
        
        for(int i=1;i<=n;i++)
        dp[i][0] = 0;//intialising first column starting from second row
        
        //here dp[i][j] represents the maximum value we can get in knapsack with capacity j considering elements upto
        //ith position
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=W;j++)
            {
                if(j>=wt[i-1])//ith element is wt[i-1] as its index is from 0
                {
                    dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]],	dp[i-1][j]);
                    		//include ith element					don't include it and hence don't
                    		//and add its value						reduce bag capacity
                    		//and reduce left capacity
                    		//of bag
                }
                else
                dp[i][j] = dp[i-1][j];//if current element has more capacity than left capacity of bag then we have
                					//no option but to leave it
            }
        }
        return dp[n][W];//maximum sum with n elements and W capacity of knapsack
    }
};
