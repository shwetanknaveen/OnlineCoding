//Problem link - https://leetcode.com/problems/wiggle-sort-ii/

class Solution {
public:
    void wiggleSort(vector<int>& nums) 
    {
        int n = nums.size(), j = n-1;
        sort(nums.begin(),nums.end());
        vector<int> ans(n);
        
        //fill largest values at the indices which have to be greater than their neighbours
        for(int i=1;i<n;i=i+2)
            ans[i] = nums[j--];
        //Now fill the remaining values in the remaining places
        for(int i=0;i<n;i=i+2)
            ans[i] = nums[j--];
        
        nums = ans;
        
    }
};

//Look for nth_element(begin itr,mid itr,end itr) functions
