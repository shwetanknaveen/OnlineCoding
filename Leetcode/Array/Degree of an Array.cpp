//Problem link - https://leetcode.com/problems/degree-of-an-array/

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int maxFreq = INT_MIN;
        unordered_map<int,int> freq,firstInd,lastInd;
        int n = nums.size();
        for(int i=0;i<n;i++) 
        {
            freq[nums[i]]++;
            maxFreq = max(maxFreq,freq[nums[i]]);
            if(firstInd.count(nums[i])==0) firstInd[nums[i]] = i;//if first index of this number hasn't been stored yet then store it
            lastInd[nums[i]] = i;
        }
        int ans = INT_MAX;
        for(int i:nums)
        {
            if(freq[i]==maxFreq)//More than one number can have frequence equal to maximum frequency in the array and in that case we have
            					//to look for smallest subarray
            {
                ans = min(ans,lastInd[i]-firstInd[i]+1);
            }
        }
        return ans;
    }
};
