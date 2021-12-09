//Problem link - https://leetcode.com/problems/remove-duplicates-from-sorted-array/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int store=0,siz = nums.size();
        for(int i=0;i<siz;i++)
        {
            nums[store++] = nums[i];
            while(i+1<siz && nums[i] == nums[i+1])//like we avoided duplicates in 3sum and 4sum
                i++;
        }
        return store;
    }
};
