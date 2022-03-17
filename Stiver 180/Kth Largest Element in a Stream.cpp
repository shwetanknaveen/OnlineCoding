//Problem link - https://leetcode.com/problems/kth-largest-element-in-a-stream/

//Approach 1 Usual approach with what we did "Find Median from data stream"
//top of minHeap will hold the ans
class KthLargest {
public:
    int k;
    priority_queue<int> maxHeap;
    priority_queue<int,vector<int>,greater<int> > minHeap;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
		for(int i:nums)
            minHeap.push(i);
        while(minHeap.size()>k)//transfer extra numbers from minHeap to maxHeap
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    int add(int val) {

        maxHeap.push(val);
        minHeap.push(maxHeap.top());//balancing heap
        maxHeap.pop();
        if(minHeap.size()>k)
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        return minHeap.top();
    }
};

//Approach 2 Using one minHeap

class KthLargest {
public:
    int k;
    priority_queue<int,vector<int>,greater<int> > minHeap;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int i:nums)
        {
           minHeap.push(i);
        }
        while(minHeap.size()>k)
            minHeap.pop();
    }
    
    int add(int val) {
        minHeap.push(val);
        if(minHeap.size()>k)
            minHeap.pop();
        return minHeap.top();
    }
};
