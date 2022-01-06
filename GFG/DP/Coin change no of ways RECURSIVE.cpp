//Problem link - https://practice.geeksforgeeks.org/problems/coin-change2448/1#
//Aditya verma link - https://www.youtube.com/watch?v=I4UR2T6Ro3w
{
  public:
    long long int UnboundknapSackRec(int W,int wt[],int n,vector<vector<long long int>> &dp)
    {
        //here dp[n][W] means the no. of ways we can get total money = W considering n coins who's corresponding values are in S[] that is in W[] array
        //initialisation(base condition) is little different from unbounded knapsack
        if(n==0 || W==0)
        {
            if(W != 0)
                return 0;//We can't get >0 money without any coin
            else return 1;//We can get 0 money if we choose no coin
        
        }
        
        if(dp[n][W]!=-1) 
        return dp[n][W];//return already remembered value
        
		if(W>=wt[n-1])//when remaining capacity of bag is greater than weight of current element
					//n-1 for wt array is used because indexing is from 0 there
        {
            dp[n][W] = UnboundknapSackRec((W-wt[n-1]),wt,n,dp)	            +		UnboundknapSackRec(W,wt,n-1,dp);
					   /*We include the coin but we call again with n               We don't include the coin hence weight
					   since we have unlimited coin supply i.e., here we            remains unchanged and element is removed
					   are dealing unbounded knapsack                               n-1
					   */		                        
            return dp[n][W];
        }
        else if(W<wt[n-1])//if current coin is larger than required remaining sum then we can't take it
        {
            dp[n][W] = UnboundknapSackRec(W,wt,n-1,dp);
            return dp[n][W];
        }
    }
    
    long long int count( int S[], int m, int n )
    {
        vector<vector<long long int>> dp(m+1,vector<long long int>(n+1,-1));
        
        //This problem is same as unbounded knapsack.
        //W is n i.e., capacity of bag = n.
        //Weight array is S[] array .
        //We treat coins as items and here we have no value optimisation rather
        //we have to fill the bag (total money = n)
        //n in unbounded knapsack is m here i.e., no. of items
        return UnboundknapSackRec(n,S,m,dp);//pass corresponding values as mentioned
                                            //above in the comment
    }
};

//Writing above code with ind varaible as index
class Solution {
  public:
    long long int unboundedKnapsack(int S[],int m,int W,vector<vector<long long int>> &dp,int ind)
    {
        if(W==0) return 1;//got the required sum hence this is a possible way
        if(ind>=m) return 0;//Haven't got reuqired sum i.e., W!=0 and exploring outside array i.e, ind>=m hence no way
        
        if(dp[ind][W] != -1) return dp[ind][W];
        
        if(W>=S[ind])
        dp[ind][W] = unboundedKnapsack(S,m,W-S[ind],dp,ind)				+			unboundedKnapsack(S,m,W,dp,ind+1);
        			   /*We include the coin but we call again with ind             We don't include the coin hence weight
					   since we have unlimited coin supply i.e., here we            remains unchanged and element is removed
					   are dealing unbounded knapsack                               and we explore next with ind+1
					   */
        
        else
        dp[ind][W] = unboundedKnapsack(S,m,W,dp,ind+1);//if current coin is larger than required remaining sum then we can't take it
        
        return dp[ind][W];
    }
    long long int count(int S[], int m, int n) {

        int W=n;
        vector<vector<long long int>> dp(m+1,vector<long long int>(W+1,-1));
        return unboundedKnapsack(S,m,W,dp,0);
    }
};

