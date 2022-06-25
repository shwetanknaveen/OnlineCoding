//Problem link - https://leetcode.com/problems/construct-target-array-with-multiple-sums/
//Best explanation - https://leetcode.com/problems/construct-target-array-with-multiple-sums/discuss/2189338/C++-oror-Simple-Code-oror-Full-Explanation
class Solution {
public:
    bool isPossible(vector<int>& target) {
        int n = target.size(),old;
        long sum = 0,restSum;
        priority_queue<int> pq;//max heap
        for(int i=0;i<n;i++)
        {
            sum += target[i];
            pq.push(target[i]);
        }
        
        while(pq.top() != 1)
        {
            sum = sum-pq.top();//remove the max element to take the sum of rest elements
            if(sum==0 || sum>=pq.top()) return false;
            
            int old = pq.top() % sum;
            
            if(old==0 && sum != 1) return false;
            
            sum += old;
            pq.pop();
            pq.push(old);
        }
        return true;
    }
};
