//Problem link - https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0,high=nums.size()-1,mid,len=nums.size();
        
		
		//Minimum will always be on the side opposite to sorted side
        //Minimum element will be the only element in the array which will be smaller than its previous element
        //Rotation index will be same as index of minimum number in the array
        while(low<=high)
        {
            mid = low + (high-low)/2;
            
            if(nums[mid] >= nums[low])//left part is sorted => look in the right part w.r.t current mid element
            {
                if(nums[mid]>nums[(mid+1)%len])//next number is smaller then it will be smallest
                    return nums[(mid+1)%len];
                low = mid + 1;//reducing the search space to right unsorted part
            }
            else//right part is sorted =>Look in the left unsorted part w.r.t current mid element
            {
                int prev;
                if(mid==0)
                    prev = len-1;
                else prev = mid-1;
                if(nums[mid]<nums[prev])//if this number is smaller than previous number then it will be smallest
                    return nums[mid];
                high = mid - 1;//reducing the search space to left unsorted part
            }
        }
        return nums[mid];//if there is only one element then low will break from loop with low = 1 which is out of bound
    }
};
