//Problem link - https://leetcode.com/problems/largest-divisible-subset/


//dp[i] gives size of temp vector at time when we are judging that whether we should pick nums[i] in our subset or not
class Solution {
public:
    void solve(vector<int> &nums,vector<int> &temp,vector<int> &ans,vector<int> &dp,int prevDiv,int ind)
    {
        if(ind>=nums.size())
        {
            if(temp.size()>ans.size())//if this subset is larger
                ans = temp;
            return;
        }
        if(nums[ind]%prevDiv==0 and dp[ind]<int(temp.size()))//While backtracking, it's better to start deciding for nums[ind] if temp has 
        													//better size than it was earlier at this stage(which is stored in dp[ind])
        {
            dp[ind] = temp.size();//update the maximum value of dp[ind]
            temp.push_back(nums[ind]);//push this number as this is divisible
            solve(nums,temp,ans,dp,nums[ind],ind+1);
            temp.pop_back();//pop out the pushed number for next call of recursion at this level
        }
        solve(nums,temp,ans,dp,prevDiv,ind+1);//skip the number if it's not divisible by the last divisor and proceed further
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1),temp,ans;
        sort(nums.begin(),nums.end());//if larger number 'a' divides a number 'b' then factors of 'a' will obviously divide 'b'
        solve(nums,temp,ans,dp,1,0);//pass the previous divisor (prevDiv) as 1 because for first element, it can always be picked if judged 
									//individually
        return ans;
    }
};
