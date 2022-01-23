//Problem link - https://leetcode.com/problems/count-elements-with-strictly-smaller-and-greater-elements/

class Solution {
public:
    int countElements(vector<int>& nums) {
        int min = *min_element(nums.begin(),nums.end());//returns iterator to the smallest element
        int max = *max_element(nums.begin(),nums.end());
        int ans=0;
        for(int i:nums)
        {
            if(i<max && i>min)
                ans++;
        }
        return ans;
    }
};
