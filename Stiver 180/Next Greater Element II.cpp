//Problem link - https://leetcode.com/problems/next-greater-element-ii/
//Video link - https://www.youtube.com/watch?v=Du881K7Jtk8&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=76

//This problem is quite similar to the previous problem "Next Greater Element I"

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> stc;
        int n=nums.size();
        vector<int> ans(n);
        
        
        for(int i=2*n-1;i>=0;i--)//We imagine that array is appended ahead of itself
        {
            while(!stc.empty() && stc.top()<=nums[i%n])
                stc.pop();
            if(i<n)//Next greater elements will be stored only for those elements whose index is smaller than n
            {
                if(!stc.empty())////top of stack is larger than this number
                {
                    ans[i] = stc.top();
                }
                else ans[i] = -1;//stack is empty and it means there is no next greater element for this number
                
            }
            stc.push(nums[i%n]);//push this number as this can be NGE for numbers on its left
            					//See "Next Greater Element I" that we are pushing nums[i] in either case
        }
        return ans; 
    }
};
