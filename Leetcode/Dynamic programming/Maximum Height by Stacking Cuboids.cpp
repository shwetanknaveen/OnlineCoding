//Problem link - https://leetcode.com/problems/maximum-height-by-stacking-cuboids/
//Video link - https://www.youtube.com/watch?v=rhEZhtoe_EQ

//We have to be greedy for height ->From 2:45 onwards, reason explained that why being greedy for height works here
class Solution {
public:
    int maxHeight(vector<vector<int>>& cS) 
    {
        int n = cS.size();
        for(auto &c:cS)
        {
            sort(c.begin(),c.end());
        }
        sort(cS.begin(),cS.end());
        int ans = 0;
        vector<int> tallestWithBaseAt(n,0);
        for(int i=0;i<n;i++)//Cuboid at i'th index will be the base cuboid
        {
            tallestWithBaseAt[i] = cS[i][2];//maximum possible height(if no other cuboid can be placed over) with this cuboid as base is 
											//height of this cuboid itself hence it is initialised with its height
            for(int j = i-1;j>=0;j--)//look for smaller cuboids that can be placed over
            {
                if(cS[i][0]>=cS[j][0] && cS[i][1]>=cS[j][1] && cS[i][2]>=cS[j][2])//if this cuboid can be placed over cuboid at ith index
                {
                    tallestWithBaseAt[i] = max(tallestWithBaseAt[i], cS[i][2]+tallestWithBaseAt[j]);
                    						/*
                    												then height which can be gained after placing cuboid at
                    												jth index will also include height of those cuboids which 
                    												can be placed over jth cuboid hence we are adding 
																	tallestWithBaseAt[j] with cS[i][2]
                    						*/
                }
            }
            ans = max(ans,tallestWithBaseAt[i]);//best possible height after checking all possibilites of keeping all cuboids at base
        }
        return ans;
    }
};
