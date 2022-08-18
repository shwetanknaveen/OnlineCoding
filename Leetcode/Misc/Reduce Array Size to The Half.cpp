//Problem link - https://leetcode.com/problems/reduce-array-size-to-the-half/

class Solution {
public:
    int minSetSize(vector<int>& arr) 
    {
        unordered_map<int,int> numFreq;
        for(int i:arr)
            numFreq[i]++;
        priority_queue<int> freq;//maxHeap
        for(auto p:numFreq)//push all the frequencies in a max heap
            freq.push(p.second);
        int target = arr.size()/2,ans = 0;//we have to half the size of array
        while(target != 0)
        {
            target -= min(freq.top(),target);//take the maximum frequencies first
            freq.pop();
            ans++;
        }
        return ans;
    }
    
};
