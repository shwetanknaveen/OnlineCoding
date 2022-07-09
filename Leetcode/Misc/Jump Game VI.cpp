//Problem link - https://leetcode.com/problems/jump-game-vi/
//Video link - https://www.youtube.com/watch?v=W8N8EeWDwKs
/*
dp[i] represents the best score to reach n-1 index from ith index hence clearly dp[n-1] = nums[n-1]
dq keeps the best option to jump ahead upto k indices at the front
*/
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        deque<int> dq;
        int n = nums.size();
        vector<int> dp(n);
        dp[n-1] = nums[n-1];
        dq.push_back(n-1);
        for(int i=n-2;i>=0;i--)
        {
            if(dq.front()-i>k) dq.pop_front();//if best option to jump ahead is more than k step then we remove it
            dp[i] = nums[i] + dp[dq.front()];//Now best score from here will be this index value + best option ahead
            while(!dq.empty() && dp[i]>dp[dq.back()])//We remove all those options which are less than this value
                dq.pop_back();                      //now this option can also be the best
            dq.push_back(i);//push this value as potential best as we do in monotonous stacks
        }
        return dp[0];//We were asked to give the best score from index 0
    }
};
