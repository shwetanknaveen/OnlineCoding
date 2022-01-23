//Problem link - https://leetcode.com/problems/rearrange-array-elements-by-sign/

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans;
        int pos,neg;
        bool posF = false,negF = false;
        int n= nums.size();
        for(int i=0;i<n;i++)
        {
            if(posF && negF)
                break;
            if(nums[i]>=0 && !posF)//if first positive hasn't been set yet
            {
                pos = i;//then set the index for first positive number
                posF = true;
            }
            if(nums[i]<0 && !negF)//if first negative hasn't been set yet
            {
                neg = i;//then set the index for first negative number
                negF = true;
            }
        }
        while(ans.size()<n)//ans will have same number of elements as that in original array
        {
            ans.push_back(nums[pos++]);//start by pushing positive number and increase positive pointer simultaneously
            
            while(pos<n && nums[pos]<0) pos++;//advance the positive pointer to next positive number
            
            ans.push_back(nums[neg++]);//push negative number and increase negative pointer simultaneously
            
            while(neg<n && nums[neg]>=0) neg++;//advance the negative pointer to next negative number
        }
        return ans;
    }
};
