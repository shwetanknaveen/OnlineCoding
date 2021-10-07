//Problem link - https://leetcode.com/problems/next-permutation/
//video link - https://www.youtube.com/watch?v=LuLCLgMElus
//direct library function - https://www.geeksforgeeks.org/stdnext_permutation-prev_permutation-c/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        bool decreasing = true;
        int first_small,swap_with;
        for(int i=size-1;i>=1;i--)
        {
            if(nums[i]>nums[i-1])
            {
                decreasing = false;//given sequence is not in decreasing order
                first_small = i-1;//found an element which is smaller than its next element
                break;
            }
        }
        if(decreasing)//if given sequence is sorted then simply reverse and return
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        
        for(int i=size-1;i>first_small;i--)//find the first element from right which is 
        									//greater than the element to be swapped
        {
            if(nums[i]>nums[first_small])
            {
                swap(nums[i],nums[first_small]);
                break;
            }
        }
        reverse(nums.begin()+first_small+1,nums.end());//after swapping, reverse elements
        												//ahead of it
    }
};
