//Problem link - https://leetcode.com/problems/best-sightseeing-pair/

class Solution {
public:
    int recHelper(vector<int> &values,int i,int count,vector<vector<int>> &dp)
    {
        if(i==values.size())//if searching for pair members outside array then score is not feasible and that shouldn't be 
            return INT_MIN;		//counted hence returning INT_MIN
        if(dp[i][count]!=-1) return dp[i][count];
        
        if(count==2)//We are yet to pick first pair member
            dp[i][count] = max(i+values[i]+recHelper(values,i+1,count-1,dp),recHelper(values,i+1,count,dp));
            				/* We pick this value as first pair member			We leave this number and look forward
            					and its index contribution in score would		for our first choice
            					be positive hence (+i)
            				*/
        
		else if(count==1)//We have to pick second pair member
            dp[i][count] = max(-i+values[i]			,					recHelper(values,i+1,count,dp));
            				/*We pick this value as second					We leave this number and look ahead
            				pair member and its index contribution			for second pair member
            				in socre would be negative hence (-i).
            				No further member has to be selected
            				hence score contribution is just -i+values[i]
            				*/
        
        return dp[i][count];
    }
    int maxScoreSightseeingPair(vector<int>& values) {
        int size = values.size();
        vector<vector<int>> dp(size,vector<int>(3,-1));
        return recHelper(values,0,2,dp);//count = 2 means we have to take 2 elements initially
    }
};
