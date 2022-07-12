//Problem link - https://leetcode.com/problems/minimum-amount-of-time-to-fill-cups/

class Solution {
public:
    int fillCups(vector<int>& amount) 
	{
        priority_queue<int> pq;
        int ans = 0;
        for(int i:amount)
        {
            if(i != 0)
                pq.push(i);
        }
        while(pq.size()>1)
        {
            int maxi = pq.top();
            pq.pop();
            int secondMaxi = pq.top();
            pq.pop();
            ans++;
            maxi--;
            secondMaxi--;
            if(maxi>0) pq.push(maxi);
            if(secondMaxi>0) pq.push(secondMaxi);
        }
        if(!pq.empty())
            ans += pq.top();
        return ans;  
    }
};
