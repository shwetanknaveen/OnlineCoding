//Problem link - https://practice.geeksforgeeks.org/problems/number-of-coins1824/1#
//Video link - https://www.youtube.com/watch?v=I-l6PBeERuc&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=16
class Solution
{
	
	//here dp[n][target] means min no. of coins that can make up total = target
    
    public:
    int minCoinChange(int val[], int target, int n,vector<vector<int>> &dp) {
	if(target == 0) return 0;//if target is 0 then no coin is required hence return 0
	if(n==0 || target<0) return (INT_MAX-1);//if there is no coin or target < 0 (i.e., in previous steps we have selected
											//such coins that we now can't get total money = target) then return INT_MAX-1
											//return INT_MAX-1 because down the stack it will be added and
											// hence INT_MAX may cause wrap around
											//for more varied test cases, to protect against wrap
	    									//arounds we can return INFINITE = INT_MAX - V in place of INT_MAX -1 and pass INFINITE 
	    									//as fixed value
	if(dp[n][target] != -1) return dp[n][target];
	int n2 = minCoinChange(val, target, n-1,dp);//don't select this coin
	int n1 = 1+minCoinChange(val, target - val[n-1], n,dp);//select this coin hence our coin count increases by 1 and now 
															//target = target - (value of selected coin)
		return dp[n][target] = min(n1 ,n2);//return the minimum coins required
    }
    
	int minCoins(int coins[], int M, int V) 
	{
	    vector<vector<int>> dp(M+1,vector<int>(V+1,-1));
	    return minCoinChange(coins,V,M,dp)<=V ? minCoinChange(coins,V,M,dp) : -1;//if input is such that there was no combination
	    																		//of coins possible then minCoinChange would have 
	    																		//returned a very large value but the maximum 
	    																		//possible ans can be V that is all coins of Rs 1
	    																		//for more varied test cases, to protect against wrap
	    																		//arounds we can return INT_MAX - V in place of INT_MAX -1
	    																		
	} 
	  
};


//Above code using index variable
class Solution{

	public:
	int getAns(int coins[],int M,int V,int index,vector<vector<int>> &dp)
	{
	    if(V==0) return 0;
	    if(index>=M || V<0) return INT_MAX-1;
	    if(dp[index][V] != -1) return dp[index][V];
	    dp[index][V] = min(getAns(coins,M,V,index+1,dp),1+getAns(coins,M,V-coins[index],index,dp));
	    return dp[index][V];
	    
	}
	int minCoins(int coins[], int M, int V) 
	{ 
	    vector<vector<int>> dp(M+1,vector<int>(V+1,-1));
	    return getAns(coins,M,V,0,dp) <= V ? getAns(coins,M,V,0,dp) : -1;
	} 
	  
};

/*IMPORTANT NOTE -  if you have to use a value  in recursive calls then don't deal that value on a variable which is local to the function
					because of which following solution gave unexpected  outputs
					Below we are using count which cause error		
class Solution
{
    public:
    int minCoinChange(int val[], int target, int n, int count,vector<vector<int>> &dp) {
	if(target == 0) return count;
	if(n==0 || target<0) return INT_MAX;
	if(dp[target][n] != -1) return dp[target][n];
		return dp[target][n] = min(minCoinChange(val, target - val[n-1], n, count+1,dp),
					minCoinChange(val, target, n-1, count,dp));
    }
    
	int minCoins(int coins[], int M, int V) 
	{
	    vector<vector<int>> dp(V+1,vector<int>(M+1,-1));
	    return minCoinChange(coins,V,M,0,dp)<=V ? minCoinChange(coins,V,M,0,dp) : -1;
	} 
	  
};
*/
