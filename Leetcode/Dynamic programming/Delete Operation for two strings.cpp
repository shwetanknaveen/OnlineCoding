//Problem link - https://leetcode.com/problems/delete-operation-for-two-strings/

//See "Striver 180/Edit Distance"

class Solution {
public:
    int solve(int ind1,int ind2,string &w1,string &w2,vector<vector<int>> &dp)
    {
        // if(ind1==w1.size() && ind2==w2.size())	//This is a extra condition which can be skipped. If both the strings have been matched
        //     return 0;							//then 0 deletion is required
        if(ind1==w1.size())//if word1 has reached to its end then extra characters in word 2 needs to be deleted
            return w2.size()-ind2;
        if(ind2==w2.size())//if word2 has reached to its end then extra characters in word 1 needs to be deleted
            return w1.size()-ind1;
        
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        
        if(w1[ind1]==w2[ind2])//if both the characters in both string at present indices are same then move ahead in both strings
            dp[ind1][ind2] = solve(ind1+1,ind2+1,w1,w2,dp);
        else
            dp[ind1][ind2] = 1+min(solve(ind1+1,ind2,w1,w2,dp),solve(ind1,ind2+1,w1,w2,dp));
            				//       Delete in word1		or 		Delete in word2
        return dp[ind1][ind2];
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(),vector<int>(word2.size(),-1));
        return solve(0,0,word1,word2,dp);
    }
};
