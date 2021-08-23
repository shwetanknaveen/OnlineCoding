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
