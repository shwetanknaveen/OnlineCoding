//Problem link - https://leetcode.com/problems/maximum-compatibility-score-sum/
class Solution {
public:
    int solve(int ind,vector<vector<int>> &studMentScore,int mentTakenMask,int &m,vector<int> &dp)
    {
        if(ind>=m) return 0;
        if(dp[mentTakenMask] != -1) return dp[mentTakenMask];
        int ans = 0;
        for(int i=0;i<m;i++)
        {
            if(!(mentTakenMask&(1<<i)))//if this mentor is not taken yet
            {
                mentTakenMask = mentTakenMask|(1<<i);//take this mentor
                ans = max(ans,studMentScore[ind][i]+solve(ind+1,studMentScore,mentTakenMask,m,dp));//look for the next student
                mentTakenMask = mentTakenMask^(1<<i);//free this mentor
            }
        }
        return dp[mentTakenMask] = ans;
    }
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int m = students.size();
        vector<vector<int>> studMentScore(m,vector<int>(m));//ith student to jth mentor
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<m;j++)
            {
                int score = 0;
                for(int k=0;k<students[i].size();k++)
                {
                    if(students[i][k]==mentors[j][k]) score++;
                }
                studMentScore[i][j] = score;
            }
        }
        vector<int> dp(pow(2,m),-1);
        return solve(0,studMentScore,0,m,dp);
    }
};
