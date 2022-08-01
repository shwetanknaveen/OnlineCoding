//Problem link - https://leetcode.com/problems/first-missing-positive/

//Approach 1 -> Using extra space
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int> set;
        for(int i:nums)
            set.insert(i);
        int count = 1;
        for(auto i:set)
        {
            if(i<=0) continue;
            if(i != count) return count;
            count++;
        }
        return count;
    }
};

//Approach 2 -> Using O(1) space and O(n) time
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        //At worst, it may be the case that all +ve numbers from 1 to n are present in nums, then n+1 will be the ans
        
        //Let's fit all the numbers in range [1,n] at their right indices
        for(int i=0;i<n;i++)
        {
            /*
            We can't check that this position contains the right number or not in the below loop i.e., we can't check that
            i+1 != nums[i] and keep on swapping till then because it is possible that there is not the right number in the nums
            to seat at this position and we will fall in infinite loop!
            Hence in other way, we check that whether this number is at it's right position or not. Hence for nums[i],right index
            is nums[i]-1 because we are storing numbers from 1 to n from 0 to n-1 indices. We check that nums[nums[i]-1] has nums[i]
            or not
            */
            while(nums[i]>0 && nums[i]<=n && nums[i] != nums[nums[i]-1])
            {
                swap(nums[i],nums[nums[i]-1]);//send this number to its right index
                                            //right position for nums[i] is nums[i]-1
            }
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i] != i+1) return i+1;
        }
        return n+1;//All numbers in range [1,n] are in nums hence n+1 is the first missing positive number
    }
};
