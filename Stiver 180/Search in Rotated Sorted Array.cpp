//Problem link - https://leetcode.com/problems/search-in-rotated-sorted-array/
//Video link - https://www.youtube.com/watch?v=r3pMQ8-Ad5s&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=65

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1,mid;
        while(low<=high)
        {
            mid = low + (high-low)/2;
            if(nums[mid]==target)
                return mid;
            
            
            //Either of the one half must be sorted and think in its term only
            if(nums[mid]>=nums[low])//left half is sorted  NOTE->Here >= sign is important
            {
                if(target>=nums[low] && target<nums[mid])
                    high = mid -1;//lies in that sorted part
                else
                    low = mid + 1;//doesn't lie in sorted part
            }
            else//right half is sorted
            {
                if(target>nums[mid] && target<=nums[high])
                    low = mid + 1;//lies in right sorted part
                else
                    high = mid -1;//doesn't lie in right sorted part
            }
        }
        
        return -1;
    }
};
