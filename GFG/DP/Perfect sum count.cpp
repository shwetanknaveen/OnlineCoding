//Problem link - https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1#
//Aditya verma link - https://www.youtube.com/watch?v=F7wqWbqYn9g&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=9

//Approach 1 -> Bottom up
class Solution{
public:
	int perfectSum(int arr[], int N, int sum)
	{
        // Your code goes here
        unsigned int modulo = 7+pow(10,9);
        vector<vector<int>> dp(N+1,vector<int>(sum+1));
        for(int j=1;j<=sum;j++)
        dp[0][j] = 0;//initialisation of first row starting from second column
        
        for(int i=0;i<=N;i++)
        dp[i][0] = 1;//initialisation of first column
                        //dp[0][0] has to be true ->0 sum is possible with no element hence dp[0][0] is true
                        
		//dp[i][j] means that what no. of subsets of the set upto ith element which can have sum = j
                        
        for(int i = 1;i<=N;i++)
        {
            for(int j=0;j<=sum;j++)//we don't start from j=1 because our required sum itself can be 0.See base
									//condition of top down code below
            {
            	//we will use arr[i-1] for ith element in arr since its indexing is from 0
                if(arr[i-1]<=j)//element at ith position has value less than or equal to j
                {
                    dp[i][j] = ((dp[i-1][j-arr[i-1]]) 		+ 		(dp[i-1][j]))%modulo;
								/*We take that element				We don't take that element and check
								and check that how many             how many subsets upto here have sum = j
								subsets upto here have sum = 			
								(j-value of this) 
								*/                    
                }
                else
                {
                dp[i][j] = (dp[i-1][j])%modulo;//if value of current element is greater than required sum = j itself then we can't 
                						//include it and have to check that how many
                						//subsets upto here can have sum = j 
                }
            }
        }
        int count = dp[N][sum];
        return count%modulo;//no. of subsets upto here (considering all N elements) which have sum = sum
	}
	  
};

//Approach 2 -> Top down that is recursive approach
class Solution{

	public:
	int perfectSumCount(int arr[],int n,int sum,int ind,int &mod,vector<vector<int>> &dp)
	{
		/*
	    if(sum==0) return 1;//if required sum is 0 then there is always 1 way to get it with picking no element
	    if(ind>=n) return 0;//if required sum is not 0 and we are exploring outside array (i.e., ind>=n) then there is 
	    					//no possible way
	    */
	    //ABOVE BASE CONDITION DOESN'T WORK WHEN OUR REQUIRED SUM IS ZERO AND ARRAY ITSELF HAS ZEROES-ABHAY ARVINDA
	    //following base codition works
	    //e.g., for input array [0 0 1] and required sum = 0, ans should be 4 and not 1. We will get 4 only when we explore
	    //whole array
	    if(ind>=n)//explored whole array
        {
            if(sum==0) return 1;//got the target
            else return 0;
        }
	    
	    if(dp[ind][sum] != -1) return dp[ind][sum]%mod;
	    
	    if(sum>=arr[ind])
	    dp[ind][sum] = perfectSumCount(arr,n,sum-arr[ind],ind+1,mod,dp) + perfectSumCount(arr,n,sum,ind+1,mod,dp);
	    				/*We take the current element and count that		We don't take current element hence we skip it
	    				how many subsets are there which have sum			and count with further elements that how many
	    				= sum-arr[ind]										subsets are there with sum = sum
						*/
	    else
	    dp[ind][sum] = perfectSumCount(arr,n,sum,ind+1,mod,dp);
	    //if current element has value greater than required sum then we have no other option but to skip it
	    
	    return dp[ind][sum]%mod;
	}
	int perfectSum(int arr[], int n, int sum)
	{
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        int mod = pow(10,9) + 7;
        return perfectSumCount(arr,n,sum,0,mod,dp);//initially we start exploring from the first index hence ind=0
	}
	  
};

