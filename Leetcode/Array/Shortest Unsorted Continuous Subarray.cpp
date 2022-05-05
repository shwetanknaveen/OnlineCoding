//Problem link - https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

//Approach 1 -> We compare this array with sorted array and see the length of that subarray which differs from sorted array
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sorted = nums;
        sort(sorted.begin(),sorted.end());
        int start,end;
        bool startSet = false;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=sorted[i])
            {
                start = i;
                startSet = true;
                break;
            }
        }
        if(!startSet) return 0;//if start index of unsorted array wasn't set then it means that whole array is sorted
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(nums[i]!=sorted[i])
            {
                end = i;
                break;
            }
        }
        return end-start+1;
    }
};

//Approach 2-> 

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1)  return 0;
        int cur_min = nums[n-1], cur_max = nums[0], left=-1, right=-1, ans;
        
        // Finding the smallest index which is greater than current_min element
        for(int i=n-2; i>=0; i--) {
            if(nums[i] <= cur_min)//We are going from right to left and this number is less than equal to minimum found upto here hence
                cur_min = nums[i];	//it indicates that we have seen sorted part upto here
            else
                left = i;//this number is greater than its right number it means it is not sorted
                		//in the end left will contain the index of the left most number which is causing the disturbance
        }
        
        // Finding the largest index which is smaller than current_max element
        for(int i=1; i<n; i++) {
            if(nums[i] >= cur_max)
                cur_max = nums[i];
            else
                right = i;
        }
        ans = left>-1 && right > -1 ? right - left + 1 : 0;
        return ans;
    }
};
