//Problem link - https://leetcode.com/problems/minimum-moves-to-reach-target-score/

//We think here in opposite way and try to bring target to 1 rather than taking 1 to target. While doing so in minimum number
// we have no doubt of halving target if we can half it

class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int count=0;
        while(target!=1)
        {
            if(maxDoubles==0)//if we can't half then we have no option but to reduce target 1 by 1
            {
                count = count + target-1;
                break;   
            }
            else if(target%2==0)//if we can half the target then simply half it
            {
                count++;
                maxDoubles--;
                target = target/2;
            }
            else//otherwise just reduce it by 1
            {
                count++;
                target = target-1;
            }
            
        }
        return count;
    }
};

//We can't use following DP methode here as our target can range in [1,10^9] which will cause memory issue
class Solution {
public:
    int solve(int target,int maxDoubles,int currVal,map<string,int> &dp)
    {
        if(target==currVal)
            return 0;
        string key = to_string(currVal)+"_"+to_string(maxDoubles);
        if(dp.find(key)!=dp.end()) return dp[key];
        
        int nWithDouble = INT_MAX-1;
        if(currVal*2<=target && maxDoubles>0)
            nWithDouble = 1+solve(target,maxDoubles-1,currVal*2,dp);
        int nWithoutDouble = 1+solve(target,maxDoubles,currVal+1,dp);
        
        return dp[key] = min(nWithDouble,nWithoutDouble);
        
    }
    int minMoves(int target, int maxDoubles) {
        int ans=INT_MAX;    
        map<string,int> dp;
        return solve(target,maxDoubles,1,dp);
    }
};
