//Problem link - https://leetcode.com/problems/kth-largest-element-in-an-array/
//See "kth largest element in a stream"
//Video link - https://www.youtube.com/watch?v=yAs3tONaf3s

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
      priority_queue<int,vector<int>,greater<int> > minHeap;
        for(int i:nums)
        {
            if(minHeap.size()<k)
                minHeap.push(i);
            else	//=> We can change this condition into more efficient one as	 "else if(minHeap.top()<i)"
            		//because numbers smaller than kth largest won't affect the answer
            {
              minHeap.push(i);
              minHeap.pop();
            }
        }
        return minHeap.top();//there are k-1 numbers bigger than minHeap.top()
    }
}; 
