//Problem link - https://leetcode.com/problems/sliding-window-maximum/
//Video link - https://www.youtube.com/watch?v=CZQGRp93K4k&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=83


/*
We will maintain a decreasing queue in which largest element will be at the front. We are travelling from left to right
and in way we keep on pushing elements which are less than element at the back.
If we find a element which is larger then no need to keep those elements on deque which are lesser than this.
We pop the element from front if it is out of scope of current window.

We need to keep elements in decreasing fashion because once largest element from front goes out of scope of current window
then we have to find the next maximum in next window
*/

//We are keeping indexes on deque and when need to compare value we put it in nums[]
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> deq;
        int n = nums.size();
        
        for(int i=0;i<n;i++)
        {   
            while(!deq.empty() && nums[deq.back()]<nums[i])//pop all the numbers from back which are smaller than this
                deq.pop_back();
            deq.push_back(i);
            while(deq.front()<(i-k+1) && !deq.empty())//at ith index, the first index of current window is i-k+1
                deq.pop_front();					//so if element at front is out of scope then remove it
            if(i>=k-1)//first window will complete at k-1 index and then next window's last element will have +1 index
                ans.push_back(nums[deq.front()]);
        }
        return ans;
    }
};
