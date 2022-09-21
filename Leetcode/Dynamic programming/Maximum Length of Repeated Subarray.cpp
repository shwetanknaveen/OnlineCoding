//Problem link - https://leetcode.com/problems/maximum-length-of-repeated-subarray/

//Approach 1 -> Top down
class Solution {
private:
	//We have to make sure that we don't write longest common subsequence logic here!
    int lcs(vector<int> &n1, vector<int> &n2, int i, int j, int &ans, vector<vector<int>> &dp)//to find longest common substring
	{
        if (i >= n1.size() || j >= n2.size()) return 0; 
        
		if(dp[i][j] != -1) return dp[i][j];
        
		int cur = 0;
        if (n1[i] == n2[j])//if this number is common
		{
            cur = lcs(n1, n2, i + 1, j + 1, ans, dp)+1; 
        }
        
        //We check by skipping one number from both arrays one by one
        lcs(n1, n2, i, j + 1, ans, dp);
        lcs(n1, n2, i + 1, j, ans, dp);
        
        //We don't save max of all three options in our ans because aur longest subarray can start from any indices in both arrays
        ans = max(ans, cur);
        return dp[i][j] = cur;
    } 
	public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        int ans = 0;
        lcs(nums1, nums2, 0, 0, ans, dp);
        return ans;
    }
};

//Approach 2 -> Bottom up

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) 
    {
        int n1 = nums1.size(), n2 = nums2.size(),ans = 0;
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        
        for(int i=1;i<=n1;i++)
        {
            for(int j=1;j<=n2;j++)
            {
                if(nums1[i-1]==nums2[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                //else dp[i][j] = 0;
                ans = max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};
