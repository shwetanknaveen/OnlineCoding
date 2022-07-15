//Problem link - https://leetcode.com/problems/product-of-array-except-self/

//Approach 1 - Time complexity = O(n), Space complexity = O(n), Using division
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        int prod = 1;//Will store the product of all elements of nums except 0
        int singleZeroIndex = -1;
        for(int i=0;i<n;i++)
        {
            if(nums[i] != 0)
                prod *= nums[i];
            else 
            {
                if(singleZeroIndex==-1) singleZeroIndex=i;//there is only one 0 in nums whose index will be stored in singleZeroIndex
                else return ans;//there are more than one zero in the array
            }
        }
        if(singleZeroIndex != -1)//there is only one zero in nums
        {
            ans[singleZeroIndex] = prod;//only at that index productExceptSelf will be non zero
            return ans;//rest are 0
        }
        for(int i=0;i<n;i++)//there is no zero in nums
        {
            ans[i] = prod/nums[i];//hence productExceptSelf will be all product divided by itself
        }
        return ans;
    }
};

//Approach 2 - Time complexity = O(n), Space complexity = O(1), Without using division
/*
At an index i,fromBegin will have product of all numbers on left of i(excluding i) and fromEnd will have product of all numbers on right of 
i(excluding i)
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(),fromBegin = 1,fromEnd = 1;
        vector<int> ans(n,1);
        for(int i=0;i<n;i++)
        {
            ans[i] *= fromBegin;//first multiplication in ans is stored
            fromBegin *= nums[i];//and then fromBegin is updated because it has to exclude nums[i]
            ans[n-i-1] *= fromEnd;
            fromEnd *= nums[n-i-1];
        }
        return ans;
    }
};
