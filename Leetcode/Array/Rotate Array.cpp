//Problem link - https://leetcode.com/problems/rotate-array/

//Approach 1 - Space complexity = O(n)
class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        int n = nums.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++)
        {
            ans[(i+k)%n] = nums[i];//kth element in the resultant vector will contain this number
        }
        nums = ans;
    }
};

//Approach 2 -
//Learn this three step method to shift by k using O(1) space
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k%nums.size();
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);//Reverse k elements from the start
        reverse(nums.begin()+k,nums.end());//Reverse all elements after k elements(excluding kth element)
    }
};
