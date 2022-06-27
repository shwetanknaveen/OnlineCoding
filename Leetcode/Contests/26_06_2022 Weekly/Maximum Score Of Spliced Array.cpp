//Problem link - https://leetcode.com/problems/maximum-score-of-spliced-array/

class Solution {
public:
    int kadane(vector<int> &arr)
    {
        int maxi = arr[0],currSum = arr[0];
        for(int i=1;i<arr.size();i++)
        {
            if(currSum+arr[i]<arr[i])
            {
                currSum = arr[i];
            }
            else
            {
                currSum += arr[i];
            }
            maxi = max(maxi,currSum);
        }
        return maxi;
    }
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int sum1,sum2,n = nums1.size();
        sum1 = accumulate(nums1.begin(),nums1.end(),0);
        sum2 = accumulate(nums2.begin(),nums2.end(),0);
        vector<int> oneMinusTwo(n),twoMinusOne(n);
        for(int i=0;i<n;i++)
        {
            oneMinusTwo[i] = nums1[i] - nums2[i];
            twoMinusOne[i] = -oneMinusTwo[i];
        }
        int res = kadane(oneMinusTwo);
        if(res>0) sum2 += res;//if difference window has some positive value then that difference will be added in sum2 because difference
        						//window is of values nums1[i] - nums2[i]
        
        res = kadane(twoMinusOne);
        if(res>0) sum1 += res;//if difference window has some positive value then that difference will be added in sum1 because difference
        						//window is of values nums2[i] - nums1[i]
        
        return max(sum1,sum2);
    }
};
