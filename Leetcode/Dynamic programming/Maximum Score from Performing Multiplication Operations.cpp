//Problem link - https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/

//Approach 1
//If we apply dp on indices of nums then it will give TLE because nums.size() <= 10^5
class Solution {
public:
    int solve(int start,int end,vector<int> &nums,vector<int> &mult,int &m,vector<vector<int>> &dp)
    {
        int multInd = start+(nums.size()-end-1);
        if(multInd >= m) return 0;
        if(dp[start][end] != -1) return dp[start][end];
        int first = solve(start+1,end,nums,mult,m,dp);
        int last = solve(start,end-1,nums,mult,m,dp);
        return dp[start][end] = max(mult[multInd]*nums[start]+first,mult[multInd]*nums[end]+last);
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) 
    {
        int m = multipliers.size(),n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(0,nums.size()-1,nums,multipliers,m,dp);
    }
};


//Approach 2
//We apply dp on start index and represent end index in terms of start index and step of multiplication so as to avoid TLE
//as following

class Solution {
public:
    int solve(int start,int multInd,vector<int> &nums,vector<int> &mult,int &m,vector<vector<int>> &dp)
    {
        int n = nums.size();
        /*
        Total taken elements are multInd among which start are taken from left hence 
        number of elements taken from right = multInd - start
        If 0 elements were picked from right then end would have been n-1 so here end would be as
        following
        */
        int end = n - (multInd - start) - 1 ;//from right, <=end we can pick elements from right side
        if(multInd >= m) return 0;
        if(dp[start][multInd] != INT_MIN) return dp[start][multInd];
        int pickL = solve(start+1,multInd+1,nums,mult,m,dp);
        int pickR = solve(start,multInd+1,nums,mult,m,dp);
        return dp[start][multInd] = max(mult[multInd]*nums[start]+pickL,mult[multInd]*nums[end]+pickR);
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) 
    {
        int m = multipliers.size(),n = nums.size();
        vector<vector<int>> dp(m,vector<int>(m,INT_MIN));
        return solve(0,0,nums,multipliers,m,dp);
    }
};
