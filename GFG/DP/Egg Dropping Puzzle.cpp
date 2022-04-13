//Problem link - https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1/#
//Video link - https://www.youtube.com/watch?v=S49zeUjeUL0&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=43


//Vairation of Matrix Chain Multiplication
class Solution
{
    public:
    
    int solve(int e,int f,vector<vector<int>> &dp)//we have e eggs and f floors
    {
        
        if(f==0 || f==1) return f;//if there is one floor or no floor then we need no testing or one testing to find the critical floor
        if(e==1) return f;//if we have only one egg then in worst case (critcal floor is top floor) we have to start checking
        					//from base floor towards upper floor and check on all the floors so that we don't break our
        					//egg before we find the critical floor
        
        if(dp[e][f]!=-1) return dp[e][f];
        
        dp[e][f] = INT_MAX;//we have to find the minimum number of attempts
        //we start dropping from 1st floor and move towards upper floors
        for(int k=1;k<=f;k++)
        {
        	
        	//we have to find minimum number of attempts and we are iterating on all floors with k
        	
        	
        										//taking max of two cases for worst case
            dp[e][f] = min(dp[e][f],	1	+	max(solve(e-1,k-1,dp)	,	solve(e,f-k,dp)));//take minimum of the attempts
            					/* 1 for this	Case-1 If egg breaks		Case-2 If egg doesn't 
            						attempt		at this kth floor then		break then we have same
            									we have one less egg		number of eggs and critical floor
            									add we need to find			will be above this floor hence we need to find
												critical floor in 			critical floor in f-k floors
            									all lower floor than this
												and there are k-1 floors
												lower than this	
            						*/
            						
            //here too we can optimize more like we did it in palindrom partitioning
        }
        return dp[e][f];
    }
    int eggDrop(int n, int k) 
    {
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        return solve(n,k,dp);
    }
};
