//Problem link - https://leetcode.com/problems/node-with-highest-edge-score/

class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<long> scores(n,0);
        for(int i=0;i<n;i++)
        {
            scores[edges[i]] += i;
        }
        long maxi = 0;
        int ans;
        for(int i=0;i<n;i++)
        {
            if(scores[i]>maxi)
            {
                ans = i;
                maxi = scores[i];
            }
        }
        return ans;
    }
};
