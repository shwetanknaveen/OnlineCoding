//Problem link - https://leetcode.com/problems/maximum-erasure-value/
//See question of this pattern in sliding window -> "Leetcode/Contest/11_06_2022 Biweekly/Count Subarrays With Score Less Than K"

//Here it is not necessary that largest window with unique numbers will give maximum score because a samller window with large numbers can
//give a larger score

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int currSum = 0,maxSum = 0,n = nums.size();
        unordered_map<int,bool> numInWind;
        //Window will expand on its right with help of j and i points to the left boundary of the current window
        for(int i=0,j=0;j<n;j++)
        {
            if(numInWind[nums[j]])//if this number is already present in the current window
            {
                while(numInWind[nums[j]])//remove all those numbers from current sum which are on left of previous occurence of this number
                						//including this number so that this window contains only unique numbers
                {
                    currSum -= nums[i];
                    numInWind[nums[i]] = false;//i is shrinking the window from left and now this number has been removed from current window
                    i++;
                }
            }
            currSum += nums[j];//Now this number can be added in the current window
            numInWind[nums[j]] = true;
            maxSum = max(currSum,maxSum);
        }
        return maxSum;
    }
};
