//Problem link - https://leetcode.com/problems/perfect-squares/
//Type of problem is unbounded knapsack
class Solution {
public:
    int solve(int presNo,int reqSum,vector<vector<int>> &dp)
    {
        if(reqSum==0) return 0;//now no more square is needed to add up to reqSum(=n)
        if(presNo==0 || reqSum<0) return INT_MAX-1;//if we have explored all the numbers down to 1 or we have added larger square in previuos
        											//step then there is no possible way to add squares to reqSum
        if(dp[presNo][reqSum] != -1) return dp[presNo][reqSum];
        return dp[presNo][reqSum] = min(1+solve(presNo,reqSum-presNo*presNo,dp)		,		solve(presNo-1,reqSum,dp));
        							/*We take presNo square but we don't decrease			We don't take the present number
        							presNo as the same number's square can be 				
        							reused again
        							
        							*/
    }
    int numSquares(int n) {
        vector<vector<int>> dp(sqrt(n)+1,vector<int>(n+1,-1));//Only those number's squares will add up to n which are <= squrt(n)
        return solve(sqrt(n),n,dp);//We start looking for numbers <=sqrt(n) because obviously number greater than it will have square greater
        							//than n hence they can't add up to n
    }
};
