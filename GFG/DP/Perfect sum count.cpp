//Problem link - https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1#
//Aditya verma link - https://www.youtube.com/watch?v=F7wqWbqYn9g&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=9
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
            for(int j=1;j<=sum;j++)
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

