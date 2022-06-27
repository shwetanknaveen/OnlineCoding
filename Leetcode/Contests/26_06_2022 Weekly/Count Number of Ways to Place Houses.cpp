//Problem link - https://leetcode.com/problems/count-number-of-ways-to-place-houses/

class Solution {
public:
    int mod = 1e9 + 7;
    int solveForOne(int ind,bool last,vector<vector<int>> &dp,int &n)
    {
        if(ind>=n)
        {
            return 1;//We have explored this combination fully hence this will be counted as 1 combination
        }
        if(dp[ind][last] != -1) return dp[ind][last];
        
        int house,noHouse;
        house = noHouse = 0;
        if(!last)//if there was no house on the last plot then we can build a house here on this plot
            house = solveForOne(ind+1,true,dp,n);
        noHouse = solveForOne(ind+1,false,dp,n);//if we don't build house on this plot
        
        return dp[ind][last] = (house + noHouse)%mod;//total possibility is sum of all possibilities
    }
    int countHousePlacements(int n) {
        vector<vector<int>> dp(n,vector<int>(2,-1));
        long forOne = solveForOne(0,false,dp,n);
        return (forOne*forOne)%mod;//total answer is product of number of ways with which we can build houses on one side becasue building
        						//houses on both sides are independent of each other
    }
};
