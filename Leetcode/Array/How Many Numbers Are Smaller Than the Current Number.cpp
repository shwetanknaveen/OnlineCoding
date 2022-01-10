//Problem link - https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> ans;
        vector<int> cs(101,0);//since 0<=nums[i]<=100 hence cs will store cumilative count of it
        for(int i:nums)
            cs[i]++;//first store the counts
        for(int i=1;i<101;i++)
            cs[i] = cs[i] + cs[i-1];//do prefix sum for counts
        for(int i:nums)
        {
            if(i==0)//if number is zero there won't be any number smaller than it
                ans.push_back(0);
            else//count the cummulative count of number just smaller than it
                ans.push_back(cs[i-1]);
        }
        return ans;
    }
};
