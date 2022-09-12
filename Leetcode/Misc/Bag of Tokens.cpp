//Problem link - https://leetcode.com/problems/bag-of-tokens/

/*
Sort tokens.
Buy at the cheapest and sell at the most expensive.
*/
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) 
    {
        sort(tokens.begin(),tokens.end());
        int start = 0,end = tokens.size()-1,ans = 0,points=0;
        while(start<=end)
        {
            if(power>=tokens[start])//if point can be gained at minimum cost(power)
            {
                points++;
                ans = max(ans,points);
                power -= tokens[start];//this much minimum power has to be expended
                start++;
            }
            else if(points>0)//We have to get some power first at cost of point
            {
                points--;
                power += tokens[end];//get maximum power
                end--;
            }
            else break;//neither point can be gained nor power then break
        }
        return ans;
    }
};
