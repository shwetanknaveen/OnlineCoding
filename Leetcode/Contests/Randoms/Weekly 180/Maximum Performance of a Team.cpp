//Problem link - https://leetcode.com/problems/maximum-performance-of-a-team/

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> effSpeed;
        long mod = 1e9+7;
        for(int i=0;i<n;i++)
        {
            effSpeed.push_back(make_pair(efficiency[i],speed[i]));
        }
        sort(effSpeed.rbegin(),effSpeed.rend());
        priority_queue<int,vector<int>,greater<int>> pq;
        long sumSpeed = 0,res = 0;
        for(auto &[eff, speed]:effSpeed)
        {
            sumSpeed += speed;
            pq.push(speed);
            if(pq.size()>k)
            {
                sumSpeed -= pq.top();
                pq.pop();
            }
            res = max(res,sumSpeed*eff);/*
                                        This guy will have minimum efficiency because effSpeed is sorted in
                                        decreasing order of efficiency. Let's suppose the guy which got added
                                        in last step got deleted because of oversize then in that case sumSpeed
                                        won't get updated and although we would have been evaluating res
                                        but it won't get updated because eff of this guy who got deleted
                                        will be even smaller with same value of sumSpeed.
                                        If some other guy gets deleted from the team and his speed is removed
                                        from sumSpeed then obviously his efficiency will also be out of
                                        consideration because efficiency of current guy is always under
                                        consideration as it is the smallest
                                        
                                        */
        }
        return int(res%mod);
    }
};
