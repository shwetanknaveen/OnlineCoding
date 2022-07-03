//Problem link - https://leetcode.com/problems/wiggle-subsequence/

//Approach 1 - Using dynamic programming

class Solution {
public:
	//last is the index of last element picked from nums in wiggle sequence. ind is the current element index which is judged that it should
	//be taken or not.nextIncr indicates that next element taken should be greater than this element hence this flag alternates between 
	//true and false.
    int solve(vector<int> &nums,int last,int ind,bool nextIncr,vector<vector<vector<int>>> &dp)
    {
        if(ind<0)
            return 0;//outside nums  won't contribute any length in wiggle sequence
        
        if(dp[last][ind][nextIncr] != -1) dp[last][ind][nextIncr];
        
        int arg1,arg2;//the conditional recursion calls are dealt in a way like it was dealt in MCM question so as to avoid TLE
        if(ind>0 && dp[ind][ind-1][!nextIncr] != -1)
            arg1 = dp[ind][ind-1][!nextIncr];//pick this number and flip the nextIncr flag
        else
            arg1 = solve(nums,ind,ind-1,!nextIncr,dp);
        if(ind>0 && dp[last][ind-1][nextIncr] != -1)
            arg2 = dp[last][ind-1][nextIncr];//don't pick this element at ind index hence leave last as it is and don't flip nextIncr flag too
        else
            arg2 = solve(nums,last,ind-1,nextIncr,dp);
        if(nextIncr)//this element is required to be greater than last picked number
        {
            if(nums[ind]>nums[last])//in this case we can either pick this number or leave this number
            {
                dp[last][ind][nextIncr] = max(1+arg1,arg2);
                						//If we pick
                						//then it increases
                						//wiggle sequence 
                						//length by 1
            }
            else//We can't pick this number at index ind as this is not larger than last picked number
            {
                dp[last][ind][nextIncr] = arg2;
            }
        }
        else//this element is required to be smaller than last picked number
        {
            if(nums[ind]<nums[last])//in this case we can either pick this number or leave this number
            {
                dp[last][ind][nextIncr] = max(1+arg1,arg2);
            }
            else//We can't pick this number at index ind as this is not smaller than last picked number
            {
                dp[last][ind][nextIncr] = arg2;
            }
        }
        return dp[last][ind][nextIncr];
    }
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size()+1;//One dummy value will be inserted later for starting condition
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
        int firstIncr,firstDcr;
        nums.push_back(-1);//least number is taken first so that when any further number is judged it can always be picked under the condition
        					//that it should be greater
        firstIncr = solve(nums,n-1,n-2,true,dp);//lets start that the first wiggle should be increasing hence we pass nextIncr as true 
        nums[n-1] = 1001;//largest number is taken first so that when any further number is judged it can always be picked under the condition
        					//that it should be smaller
        firstDcr = solve(nums,n-1,n-2,false,dp);
        return max(firstIncr,firstDcr);//maximum of both the cases is the answer
    }
};

//Approach 2 -> See solution 5 of leetcode

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size(),prevDiff,count,diff;
        if(n<2) return n;
        prevDiff = nums[1] - nums[0];
        count = prevDiff == 0 ? 1 : 2;
        for(int i=2;i<n;i++)
        {
            diff = nums[i] - nums[i-1];
            if((diff<0 && prevDiff>=0) || (diff>0 && prevDiff<=0))
            {
                count++;
                prevDiff = diff;
            }
        }
        return count;
    }
};

