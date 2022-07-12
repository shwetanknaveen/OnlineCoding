//Problem link - https://leetcode.com/problems/matchsticks-to-square/
//See also the problem of whose variation this is but that can't be solve with recursion only - "Leetcode/Dynamic Programing/Partition to K Equal Sum Subsets"
class Solution {
public:
    bool solve(int ind,vector<int> &sticks,vector<int> &sides,int &side)
    {
        if(ind>=sticks.size()) return true;//all matchsticks have been allocated
        bool ret = false;//let's suppose this matchstick can't be taken in any of the side
        for(int i=0;i<4;i++)
        {
            if(sides[i]+sticks[ind]<=side)
            {
                sides[i] += sticks[ind];//give this matchstick to this side
                ret = ret || solve(ind+1,sticks,sides,side);//look for other matchsticks
                sides[i] -= sticks[ind];//remove the matchstick for other recursive calls
            }
        }
        return ret;
    }
    bool makesquare(vector<int>& matchsticks) {
        int perim = 0;
        for(int i:matchsticks)
        {
            perim += i;
        }
        if(perim%4 != 0) return false;//total perimeter must be divisible by 4
        sort(matchsticks.rbegin(),matchsticks.rend());//it fails makes some test cases fail early if they have to fail e.g., [8,4,4,4] -> 8 can't be taken in any of the sides of the square
        int side = perim/4;
        vector<int> sides(4,0);
        return solve(0,matchsticks,sides,side);
    }
};
