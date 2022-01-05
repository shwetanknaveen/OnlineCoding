//Problem link - https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1#
//Aditya verma - https://www.youtube.com/watch?v=-GtpxG6l_Mc&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=11

//Approach -1 Bottom Up approach
class Solution{
	
  public:
  void initialisePossibleSums(int N, int arr[], int sum,vector<vector<bool>> &dp){
        // code here 
        for(int j=1;j<sum+1;j++)
        dp[0][j] = false;//initialisation of first row starting from second column
        
        for(int i=0;i<N+1;i++)
        dp[i][0] = true;//initialisation of first column
                        //dp[0][0] has to be true ->0 sum is possible with no element hence dp[0][0] is true
                        
	//dp[i][j] means that whether we can have a sum = j considering elements upto ith position in the given arr                        
                        
        for(int i = 1;i<N+1;i++)
        {
            for(int j=1;j<sum+1;j++)
            {
            	//we will use arr[i-1] for ith element in arr since its indexing is from 0
                if(arr[i-1]<=j)//element at ith position has value less than or equal to j
                {
                    dp[i][j] = (dp[i-1][j-arr[i-1]]) 		|| 		(dp[i-1][j]);
								/*We take that element				We don't take that element and 
								and check whether sum = 			check whether sum = j is possible with
								j-value of this is possible 		previous elements or not
								with previous elements or not
								*/                    
                }
                else
                {
                dp[i][j] = dp[i-1][j];//if value of current element is greater than required sum = j itself then we can't 
                						//include it and have to check whether we can get sum = j without taking it
                }
            }
        }
    }
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum = 0;
	    for(int i=0;i<n;i++)
	    sum += arr[i];
	    
	    vector<vector<bool>> dp(n+1,vector<bool>(sum+1));
	    initialisePossibleSums(n,arr,sum,dp);
	    //now here our dp array is initialised in which //dp[i][j] means that 
	    //whether we can have a sum = j considering elements upto ith position in
	    //the given arr                        
	    
	    //we have two subsets s1 and s2
	    //difference is (s2 - s1). This difference would be absolute if we allow s1 from
	    //0 to sum/2 only
	    //Therefore diff = s2 - s1 = (sum - s1) - s1 = (sum - 2*s1)
	    //so difference can be minimum when s1 is as near as possible to sum/2
	    
	    for(int j=sum/2;j>=0;j--)
	    {
	        
	        //in last row of dp we check that which is the largest possbile value
	        //for s1 near sum/2 and we know diff = (sum - 2*s1)
	        if(dp[n][j]) return (sum - 2 * j);
	        //dp[i][j] means that whether we can have a sum = j considering elements
	        //upto ith position in the given arr                        
	    }
	    
	} 
};

//Approach 2- Top down approach that is recursive approach


class Solution{

  public:
    int knapSack(int arr[],int n,int ind,vector<vector<int>> &dp,int W)//simple 01 knapsack
    {
        if(W==0 || ind>=n) return 0;
        
        if(dp[ind][W] != -1) return dp[ind][W];
        
        if(W>=arr[ind])
        dp[ind][W] = max(arr[ind] + knapSack(arr,n,ind+1,dp,W-arr[ind]),
                        knapSack(arr,n,ind+1,dp,W));
        else
        dp[ind][W] = knapSack(arr,n,ind+1,dp,W);
        
        return dp[ind][W];
        
    }
	int minDifference(int arr[], int n)  { 
	    int totalSum=0;
	    for(int i=0;i<n;i++)
	    totalSum += arr[i];
	    int target = totalSum/2;//difference will be minimum when one of subset will have a sum as close as to totalSum/2
	    vector<vector<int>> dp(n+1,vector<int>(target + 1, -1));
	    int subSet1 = knapSack(arr,n,0,dp,target);//get the sum of one subset as close as totalSum/2
	    int subSet2 = totalSum - subSet1;
	    return abs(subSet2-subSet1);
	} 
};

