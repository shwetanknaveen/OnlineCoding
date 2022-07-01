//Problem link - https://leetcode.com/problems/decode-ways/

class Solution {
public:
    int solve(int ind,string &s,vector<int> &dp)
    {
        if(ind>=s.length())//string s has exhausted hence this is one possible way of partition
            return 1;
        if(dp[ind] != -1) return dp[ind];
        int takeOne,takeTwo;
        takeOne = takeTwo = 0;
        if(stoi(s.substr(ind,1))>0)//Encoding starts from 1 hence one digit code must be >0
        {
            takeOne = solve(ind+1,s,dp);
            if(ind+1<s.length() && stoi(s.substr(ind,2))<=26)//We can think of taking two only if we can first be able to take one hence this if is nested
            /*
            if next value has to be     
            taken then it must be
            inside the string s
            that's why ind+1<s.length()
            is checked
            */
            {
                takeTwo = solve(ind+2,s,dp);
            }
        }
        
        return dp[ind] = takeOne + takeTwo;//if some previous partition would have been illegal 
                                            //then this would return 0
    }
    int numDecodings(string s) {
        vector<int> dp(s.length(),-1);
        return solve(0,s,dp);
    }
};
