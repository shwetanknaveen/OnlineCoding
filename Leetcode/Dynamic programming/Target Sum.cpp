//Problem link - https://leetcode.com/problems/target-sum/
//Aditya verma - Target sum - https://www.youtube.com/watch?v=Hw6Ygp3JBYw&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=12
//Aditya verma - No. of subsets with given difference - https://www.youtube.com/watch?v=ot_XBHyqpFc&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=11

//Approach 1 -> Bottom up approach
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {//target will act as difference here->count no. of subsets with 
    													//given difference
		target = abs(target);//target can be a large negative value too hence in that case subsetSum = (target + totalSum)/2
							//can be a negative value and hence allocation of dp vector will be an issue
							//We know that diff is target that is S1-S2=target or S2-S1=target  													
        int totalSum = 0;
        
        for(int i: nums)
            totalSum += i;
        
        
        //Now the code below counts no. of subsets with subset sum = (target + totalSum)/2
        //since this problem has reduced to the problem of no. of subsets with given difference
        //in which we were counting the number of subsets with sum = (totalSum+diff)/2;
        //here difference is target
        
        //For the problem of no. of subsets with given difference
        /*We have to divide the given set into two subsets such that difference of the two
        subsets = diff
        Let those subsets are S1 and S2 and let's suppose S1 is the larger subset in case if 
        division is not equal
        Therefore,
                    S1 + S2 = totalSum and S1 - S2 = diff
                    -> S1 = (totalSum + diff)/2;
                    
                    
        */
        
        if((target + totalSum)&1) return 0;//since required subset sum can't be fractional
        
        int subsetSum = (target + totalSum)/2;
        int N = nums.size();
        vector<vector<int>> dp(N+1,vector<int>(subsetSum+1));
        
        //dp[i][j] means that what no. of subsets of the set upto ith element which can have sum = j
        
        for(int j=1;j<=subsetSum;j++)
        dp[0][j] = 0;//initialisation of first row starting from second column
        
        for(int i=0;i<=N;i++)
        dp[i][0] = 1;//initialisation of first column
                        //dp[0][0] has to be true ->0 sum is possible with no element hence                      
        
        for(int i = 1;i<=N;i++)
        {
            for(int j=0;j<=subsetSum;j++)//we don't start from j=1 because our required sum itself can be 0.See base
										//condition of top down code below
            {
            					//we will use nums[i-1] for ith element in arr since its indexing is from 0
                if(nums[i-1]<=j)//element at ith position has value less than or equal to j
                {
                    dp[i][j] = ((dp[i-1][j-nums[i-1]]) 		+ 		(dp[i-1][j]));                    
                    			/*We take that element				We don't take that element and check
								and check that how many             how many subsets upto here have sum = j
								subsets upto here have sum = 			
								(j-value of this) 
								*/
                    
                    
                }
                else
                {
                	dp[i][j] = (dp[i-1][j]);//if value of current element is greater than required sum = j itself then we can't 
                							//include it and have to check that how many
                							//subsets upto here can have sum = j 
                }
            }
        }
        return dp[N][subsetSum];
    }
};

//Approach 2 -> Top down approach
class Solution {
public:
    int countSubsets(vector<int> &nums,int target,vector<vector<int>> &dp,int ind)
    {
        /*
        if(target==0) return 1;
        if(ind>=nums.size()) return 0;
        */
        
        //ABOVE BASE CONDITION DOESN'T WORK WHEN OUR REQUIRED SUM IS ZERO AND ARRAY ITSELF HAS ZEROES-ABHAY ARVINDA
	    //following base codition works
	    //e.g., for input array [0 0 1] and required sum = 0, ans should be 4 and not 1. We will get 4 only when we explore
	    //whole array
        //Above base condition doesn't work as suppose our original target itself is 0 then we can't return simply looking
        //at the target value as 0 and without exploring the whole array that how many subsets are there which have sum=0
        
        if(ind>=nums.size())//explored whole array
        {
            if(target==0) return 1;//got the target
            else return 0;
        }
        
        if(dp[ind][target] != -1) return dp[ind][target];
        
        if(target>=nums[ind])
            dp[ind][target] = countSubsets(nums,target-nums[ind],dp,ind+1) + countSubsets(nums,target,dp,ind+1);
        else
            dp[ind][target] = countSubsets(nums,target,dp,ind+1);
        return dp[ind][target];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0;
        for(int i:nums)
            totalSum += i;
        target = abs(target);//target can be a large negative value too hence in that case subsetSum = (target + totalSum)/2
							//can be a negative value and hence allocation of dp vector will be an issue
							//We know that diff is target that is S1-S2=target or S2-S1=target  													
        int newTarget = (totalSum+target)/2;
        if((totalSum+target)&1) return 0;
        vector<vector<int>> dp(nums.size()+1,vector<int>(newTarget+1,-1));
        return countSubsets(nums,newTarget,dp,0);
    }
};
