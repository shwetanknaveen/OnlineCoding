//Problem link - https://leetcode.com/problems/count-special-integers/

class Solution {
public:
    
    int dfs(string &num,int ind,int mask,bool canBeGreater,vector<vector<vector<int>>> &dp)
    {
        if(ind==num.size()) return 1;
        if(dp[mask][ind][canBeGreater] != -1) return dp[mask][ind][canBeGreater];
        
        int ans = 0;
        for(char c='0';c<='9';c++)
        {
            if((ind==0 and c=='0') or (mask&(1<<(c-'0')))) continue;//can't take 0 at first index or a number which has 
																	//already been taken
            
            int updateMaskOnTake = mask|(1<<(c-'0'));
            if(c<num[ind]) ans += dfs(num,ind+1,updateMaskOnTake,true,dp);//if we take a smaller number on significant digits
            																//then later on we can take larger numbers also
            																//at less significant places
            else if(c==num[ind]) ans += dfs(num,ind+1,updateMaskOnTake,canBeGreater,dp);
            else if(c>num[ind] && canBeGreater) ans += dfs(num,ind+1,updateMaskOnTake,canBeGreater,dp);//If we wish to take
            																//larger number here then we should assure that
            																//earlier we took smaller number and had passed
            																//canBeGreater = true
        }
        return dp[mask][ind][canBeGreater] = ans;
    }
    int countSpecialNumbers(int n) 
    {
        string num = to_string(n);
        int nDig = num.size(), ans = 0;
        vector<vector<vector<int>>> dp(1024,vector<vector<int>>(nDig,vector<int>(2,-1)));//dp[mask][ind][canBeGreater]
        //mask will mark that which digit from 0 to 9 has been taken hence its max value can be 1111111111 (10 times 1)
        //i.e., 1023
        
        //Count all numbers having smaller number of digits than given number and have all digits as unique
        for(int dig=1;dig<nDig;dig++)
        {
            int count = 1,start = 9;
            for(int place=1;place<=dig;place++)
            {
                count *= start;
                if(place != 1) start--;//multiplication goes like 9 x 9 x 8 x 7 x 6 x 5.......
            }
            ans += count;
        }
        //Now we will be counting number of numbers smaller than n but have same number of digits and all digits are unique
        ans += dfs(num,0,0,false,dp);//initially on the first digit, digit value can't be greater than num[0] hence we pass false
        return ans;
    }
};
