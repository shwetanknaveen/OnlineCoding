//Problem link - https://www.geeksforgeeks.org/partition-problem-dp-18/
//Aditya verma link- https://www.youtube.com/watch?v=UmMh7xp07kY&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=8
class Solution{
public:

    bool isSubsetSum(int N, int arr[], int sum){
        // code here 
        vector<vector<bool>> dp(N+1,vector<bool>(sum+1));
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
								with previous elements are not
								*/                    
                }
                else
                {
                dp[i][j] = dp[i-1][j];//if value of current element is greater than required sum = j itself then we can't 
                						//include it and have to check whether we can get sum = j without taking it
                }
            }
        }
        return dp[N][sum];//whether we can get sum = sum considering all N elements
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int totalSum=0;
        for(int i=0;i<N;i++)
        totalSum+=arr[i];
        if(totalSum&1) return 0;//if total sum is odd then we can't have equal partition at all
        return isSubsetSum(N,arr,totalSum/2) ? 1 : 0;//check whether subset sum is possible for totalSum/2
        
    }
};

