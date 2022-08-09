//Problem link - https://leetcode.com/problems/count-vowels-permutation/

class Solution {
public:
    vector<char> vowels = {'a','e','i','o','u'};
    int mod = 1e9+7;
    int solve(int ind,int lastChar,int &n,vector<vector<int>> &dp)
    {
        if(ind==n) return 1;//filled the whole string so this is one possible string
        if(dp[ind][lastChar] != -1) return dp[ind][lastChar];
        long ans = 0;
        for(char c:vowels)
        {
            if(ind==0)//this is the first character then here any character can be present
            {
                ans = (ans + solve(ind+1,c-'a',n,dp))%mod;
            }
            else
            {
                if(char(lastChar+'a')=='a' && c=='e')//a can only be followed by e
                    ans = (ans + solve(ind+1,c-'a',n,dp))%mod;
                else if(char(lastChar+'a')=='e' && (c=='a' || c=='i'))//e can be followed by a or i
                    ans = (ans + solve(ind+1,c-'a',n,dp))%mod;
                else if(char(lastChar+'a')=='i' && c != 'i')// i can't follow i
                    ans = (ans + solve(ind+1,c-'a',n,dp))%mod;
                else if(char(lastChar+'a')=='o' && (c=='i' || c=='u'))//o can be followed by i or u
                    ans = (ans + solve(ind+1,c-'a',n,dp))%mod;
                else if(char(lastChar+'a')=='u' && c=='a')//u can be followed by a
                    ans = (ans + solve(ind+1,c-'a',n,dp))%mod;
            }
        }
        return dp[ind][lastChar] = ans;
    }
    int countVowelPermutation(int n) {
        vector<vector<int>> dp(n+1,vector<int>(26,-1));
        return solve(0,0,n,dp);//it doesn't matter that what we pass for lastChar for first character
    }
};
