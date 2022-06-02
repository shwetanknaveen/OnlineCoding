//Problem link - https://leetcode.com/problems/subarray-sum-equals-k/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;//(number of subsets with sum) -> count
        int n = nums.size();
        mp[0] = 1;//An empty set with 0 sum
        vector<int> pref(n,0);
        pref[0] = nums[0];
        for(int i=1;i<n;i++)
        {
            pref[i] = pref[i-1]+nums[i];
        }
        int count = 0;
        for(int i:pref)
        {
            count += mp[i-k];//current sum in pref is i hence how many subsets were there
                            //which had sum = i-k so that i-(i-k) = k
            mp[i]++;
        }
        return count;
    }
};
