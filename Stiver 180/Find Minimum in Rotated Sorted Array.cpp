//Problem link - https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0,high=nums.size()-1,mid,len=nums.size();
        
		
		//Minimum will always be on the side opposite to sorted side
        
        while(low<=high)
        {
            mid = low + (high-low)/2;
            
            if(nums[mid] >= nums[low])//left part is sorted
            {
                if(nums[mid]>nums[(mid+1)%len])//next number is smaller then it will be smallest
                    return nums[(mid+1)%len];
                low = mid + 1;
            }
            else//right part is sorted
            {
                int prev;
                if(mid==0)
                    prev = len-1;
                else prev = mid-1;
                if(nums[mid]<nums[prev])//if this number is smaller than previous number then it will be smallest
                    return nums[mid];
                high = mid - 1;
            }
        }
        return nums[mid];//if there is only one element then low will break from loop with low = 1 which is out of bound
    }
};
