//Problem link - https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1
//Aditya verma link- https://www.youtube.com/watch?v=UmMh7xp07kY&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=8

//Approach 1 -> Bottom up
class Solution{
public:

    bool isSubsetSum(int N, int arr[], int sum){
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


//Approach 2 -> Top down that is recursive approach

class Solution{
public:
    int equalPartHelper(int N,int arr[],vector<vector<int>> &dp,int ind,int sum)
    {
        if(sum==0) return 1;//sum=0 is always possible with picking no element
        if(ind>=N) return 0;//here sum!=0 and ind>=N, which means we are exploring outside array, hence it is not possible
        if(dp[sum][ind] != -1) return dp[sum][ind];
        
        if(sum>=arr[ind])
        dp[sum][ind] = (equalPartHelper(N,arr,dp,ind+1,sum-arr[ind])==1 || equalPartHelper(N,arr,dp,ind+1,sum))? 1 : 0;
        				/*We take that element								We don't take that element and 
						and check whether sum = 							check whether sum = sum is possible with
						sum-value of this is possible 						next elements or not
						with next elements or not
								*/
        else
        dp[sum][ind] = equalPartHelper(N,arr,dp,ind+1,sum);
        //if value of current element is greater than required sum itself then we can't 
		`//include it and have to check whether we can get sum without taking it
        
        return dp[sum][ind];
    }
    int equalPartition(int N, int arr[])
    {
        int totalSum = 0;
        for(int i=0;i<N;i++)
            totalSum += arr[i];
        /*
		NOTE -> We can use for each loop for array if it's declared in the same scope like as shown here-
		https://www.geeksforgeeks.org/g-fact-40-foreach-in-c-and-java/
		but we can't use it in some other function where it is passed like here
		*/    
        
        if(totalSum&1) return 0;//if total sum is odd then we can't have equal partition at all
        vector<vector<int>> dp(totalSum/2+1,vector<int>(N+1,-1));//we will be passing totalSum/2 hence full dp array for totalSum won't be required
        //dp[j][i] means that whether we can have a sum = j considering elements upto ith position in the given arr                        
        
        return equalPartHelper(N,arr,dp,0,totalSum/2);//check whether subset sum is possible for totalSum/2
        											//initially we start exploring from the first index hence ind=0
    }
};

