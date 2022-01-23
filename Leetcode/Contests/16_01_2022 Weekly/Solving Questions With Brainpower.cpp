//Problem link - https://leetcode.com/problems/solving-questions-with-brainpower/
class Solution {
public:
    long long solve(vector<vector<int>> &questions,int &n,int ques,map<int, long long> &dp)
    {
        if(ques >= n)//can't solve questions out of question list
            return 0;
        if(dp.find(ques)!=dp.end()) return dp[ques];
        
        return dp[ques] = max(questions[ques][0] + solve(questions,n,ques+questions[ques][1]+1,dp),solve(questions,n,ques+1,dp));
        					/*Solve this quesiton and skip required number of questions					Don't solve this quest-
        																								-ion and think from next
        																								question
        					*/
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        map<int,long long> dp;
        return solve(questions,n,0,dp);
    }
};
