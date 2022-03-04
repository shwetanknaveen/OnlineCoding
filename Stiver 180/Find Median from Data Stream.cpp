//Problem link - https://leetcode.com/problems/find-median-from-data-stream/
//Video link - https://www.youtube.com/watch?v=il4LgXUjSu4&list=PLudlC33BR8eEiSWH654z2GKEF3Ckz6QWB&index=2

class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        
        if(minHeap.size()>maxHeap.size())
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        return maxHeap.size()>minHeap.size()?maxHeap.top():double(maxHeap.top()+minHeap.top())/2.0;
    }
};
