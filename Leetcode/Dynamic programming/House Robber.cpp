//Problem link - https://leetcode.com/problems/house-robber/
//Related problem - 01 Knapsack
class Solution {
public:
    
    int getAns(int look,vector<int> &maxProfitUptoHere,vector<int> &nums)
    {
        if(look>=maxProfitUptoHere.size())//if looking outside house ranges
        {
          return 0;  
        }
        if(maxProfitUptoHere[look]!=-1)//it has been updated earlier
            return maxProfitUptoHere[look];
        maxProfitUptoHere[look] = max(nums[look]+getAns(look+2,maxProfitUptoHere,nums),
                                         getAns(look+1,maxProfitUptoHere,nums));
        //If I choose to rob this(look) house then I can't rob the next one hence I will then look forward from look+2 but 
		//if I don't rob this house then I can rob the next one without adding this house value
        return maxProfitUptoHere[look];
    }
    int rob(vector<int>& nums) {
        vector<int> maxProfitUptoHere;	`//our dp array
        for(int i=0;i<nums.size();i++)
            maxProfitUptoHere.push_back(-1);
       return getAns(0,maxProfitUptoHere,nums);//we start looking from index=0
    }
};
