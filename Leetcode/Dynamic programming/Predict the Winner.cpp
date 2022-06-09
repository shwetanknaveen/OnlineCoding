//Problem link - https://leetcode.com/problems/predict-the-winner/

class Solution {
public:
    int scoreOfOne(vector<int> &nums,int i,int j,vector<vector<int>> &dp)
    {
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j]; 
        int pickI = 	nums[i] 		+ 			min(scoreOfOne(nums,i+2,j,dp),scoreOfOne(nums,i+1,j-1,dp));
        			/*Suppose A picks nums[i]		now	B can pick nums[i+1]	or		B can pick nums[j]
        											B will choose among these two options such that after B's turn
        											A gets minimum score because B is also playing optimally hence we take
        											minimum of these two options to add in A's score
        			
        			*/
        int pickJ = 	nums[j] 		+ 			min(scoreOfOne(nums,i,j-2,dp),scoreOfOne(nums,i+1,j-1,dp));
        			/*Suppose A picks nums[j]		now	B can pick nums[j-1]	or		B can pick nums[i]
        											B will choose among these two options such that after B's turn
        											A gets minimum score because B is also playing optimally hence we take
        											minimum of these two options to add in A's score
        			
        			*/
        return dp[i][j] = max(pickI,pickJ);//Since A is playing optimally so A takes maximum of available paths
    }
    bool PredictTheWinner(vector<int>& nums) {
        int totalScore = 0;
        for(int i:nums) totalScore += i;
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        int maxOneScore = scoreOfOne(nums,0,n-1,dp);
        return maxOneScore>=(totalScore-maxOneScore);//A's score should be greater than or equal to that of B
    }
};
