//Problem link - https://leetcode.com/problems/sort-array-by-parity/

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int ending = nums.size()-1, start = 0;//all the numbers pointed to the right of ending will be odd numbers
        while(start<ending)
        {
            if(nums[start]&1)//present number at start is odd
            {
                swap(nums[start],nums[ending--]);//we are not sure that what is coming at start is odd or even hence we are not increasing
                continue;						//the value of start
            }
            start++;//look for next number and swap them to right end if they are odd
        }
        return nums;
    }
};
