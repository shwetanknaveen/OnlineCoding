//Problem link - https://leetcode.com/problems/count-sorted-vowel-strings/

//We assume that all the vowels are present in a vector in sorted order starting from index 0 to 4. We will build the string only in sorted
//order
class Solution {
public:
    int helper(int ind,int len,int &n,vector<vector<int>> &dp)
    {
        if(len==n)//if length of the present built string is reached to the required length then this is one possible combination
            return 1;
        if(ind>4) return 0;//if we are using alphabet outside a,e,i,o or u then no possible string with given constraint
        if(dp[ind][len] != -1) return dp[ind][len];
        int n1 = helper(ind,len+1,n,dp);//We use this vowel in the string and hence increase the length but we don't increase ind as we can
        								//use this vowel again (Like unbounded knapsack)
        int n2 = helper(ind+1,len,n,dp);//We don't use this vowel and go on further to explore for building the string with remaining vowels
        return dp[ind][len] = n1+n2;
    }
    int countVowelStrings(int n) {
        vector<vector<int>> dp(5,vector<int>(n+1,-1));
        return helper(0,0,n,dp);
    }
};
