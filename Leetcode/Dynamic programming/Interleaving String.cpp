//Problem link - https://leetcode.com/problems/interleaving-string/

class Solution {
public:
    bool solve(int ind1,int ind2,string &s1,string &s2,string &s3,vector<vector<int>> &dp)
    {
        if(ind1 == s1.length() && ind2 == s2.length())//both strings (s1 and s2) have been consumed and matched with s3
            return true;
        if(ind1 == s1.length())// => ind2 < s2.length() => remaining string of s2 should match with remaining part of string s3
            return (s2.substr(ind2,s2.length()-ind2)).compare(s3.substr(ind1+ind2,s3.length()-(ind1+ind2)))==0?true:false;
        if(ind2 == s2.length())// => ind1 < s1.length() => remaining string of s2 should match with remaining part of string s3
            return (s1.substr(ind1,s1.length()-ind1)).compare(s3.substr(ind1+ind2,s3.length()-(ind1+ind2)))==0?true:false;
        
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        
        bool inS1 = false, inS2 = false;
        if(s1[ind1]==s3[ind1+ind2])//if this character in s3 matches with character of string s1 then we can proceed further in string s1 for matching
            inS1 = solve(ind1+1,ind2,s1,s2,s3,dp);
        if(s2[ind2]==s3[ind1+ind2])//if this character in s3 matches with character of string s2 then we can proceed further in string s2 for matching
            inS2 = solve(ind1,ind2+1,s1,s2,s3,dp);
        return dp[ind1][ind2] = inS1 || inS2;//full mathing should be possible either way
        
    }
    bool isInterleave(string s1, string s2, string s3) 
    {
        int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
        if(len3 != len1 + len2) return false;//=> s3 length should be sum of length of s1 and s2
        vector<vector<int>> dp(len1,vector<int>(len2,-1));
        return solve(0,0,s1,s2,s3,dp);
    }
};
