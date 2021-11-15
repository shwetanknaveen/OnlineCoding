//Problem link - https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1
class Solution
{

	public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(int arr[], int n){
        int maxSum,currSum,allNeg,smallestNeg;
        maxSum=currSum=0;
        allNeg=1;
        smallestNeg = INT_MIN;
        for(int i=0;i<n;i++){
            currSum += arr[i];
            if(currSum>maxSum){
                maxSum=currSum;
            }
            if(currSum<0){
                currSum=0;
            }
            if(arr[i]>=0) allNeg = 0;
            if(arr[i]<0 && arr[i]>smallestNeg) smallestNeg = arr[i];
        }
        if(allNeg) return smallestNeg;//if all the array elements are negative
        return maxSum;
        
    }	
};

/*
CODE SUBMITTED ON LEETCODE

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0,n=nums.size(),allNeg = 1,leastNeg=INT_MIN,maxSum=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>=0) allNeg = 0;
            else leastNeg = max(leastNeg,nums[i]);
            
            maxSum = max(maxSum,sum);
            sum += nums[i];
            if(sum<0)
            sum = 0;
            
        }
        if(allNeg) return leastNeg;
        else return max(maxSum,sum);
    }
};
*/
