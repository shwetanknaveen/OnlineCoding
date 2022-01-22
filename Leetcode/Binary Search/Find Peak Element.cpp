//Problem link - https://leetcode.com/problems/find-peak-element/

class Solution {
public:
    bool isAns(vector<int> &nums,int &ind,int &n)
    {
        if(ind==0)//if it's the first number, it just need to be compared with next number
        {
            if(nums[ind]>nums[ind+1]) return true;
            else return false;
        }
        if(ind==n-1)//if it's the last number, it just need to be compared with previous number
        {
            if(nums[ind]>nums[ind-1]) return true;
            else return false;
        }
        if(nums[ind]>nums[ind+1] && nums[ind]>nums[ind-1]) return true;
        return false;//default case in else
    }
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1) return 0;//if there is only one element in the array, it will be the peak element
        
        //Now we have made sure that our array has more than 1 element
        int n=nums.size();
        int low=0,high=n-1,mid;
        while(low<=high)
        {
            mid = low + (high-low)/2;
            if(isAns(nums,mid,n)) return mid;
            
			/*
			It is given that no two consecutive numbers are equal hence if this number at mid index is not answer and next
			number is greater then there will be definitely one peak element on the right side of mid. Since the right number
			is larger so either it will go on increasing (in that case, last number will be answer) or it will decrease so-
			-mewhere and that will be answer because it will be greater than its left side(it went increasing) and also
			greater than right side
			*/
			
			if(nums[mid]<nums[mid+1])
                low = mid+1;
            else
                high = mid-1;
        }
        return 0;//just to prevent compiler warning otherwise there will always be an answer as it is given that no to 
        		//consecutive elements are equal
    }
};
