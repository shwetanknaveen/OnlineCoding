//Problem link - https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1
//Same question as "Longest Increasing Subsequence". Here we have to maximise the subsequence sum value rather than its size

class Solution{
		

	public:
	int helper(vector<int> &nums,int ind,int prevValInd,vector<vector<int>> &dp)
	{
	    if(ind<0) return 0;
	    
	    if(dp[ind][prevValInd] != -1) return dp[ind][prevValInd];
	    
	    if(nums[ind]<nums[prevValInd])
	    {
	        dp[ind][prevValInd] = max(nums[ind]+helper(nums,ind-1,ind,dp),helper(nums,ind-1,prevValInd,dp));
	    }
	    else
	    {
	        dp[ind][prevValInd] = helper(nums,ind-1,prevValInd,dp);
	    }
	    return dp[ind][prevValInd];
	}
	int maxSumIS(int arr[], int n)  
	{  
	    vector<int> nums;
	    for(auto i=0;i<n;i++)
	        nums.push_back(arr[i]);
	   nums.push_back(INT_MAX);
	   vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
	   return helper(nums,n-1,n,dp);
	}  
};
