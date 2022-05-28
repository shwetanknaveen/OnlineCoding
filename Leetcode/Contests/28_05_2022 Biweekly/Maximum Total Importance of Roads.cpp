//Problem link - https://leetcode.com/problems/maximum-total-importance-of-roads/

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> indegree(n,0);
        for(auto v:roads)
        {
            //This Edge contributes to the indegree of both vertices
            indegree[v[0]]++;
            indegree[v[1]]++;
        }
        sort(indegree.rbegin(),indegree.rend());//sort in descending order
        long long ans = 0;
        for(long long i:indegree)
        {
            ans += i*n;//give the highest number to the node having highest indegree because it will
                        //be added maximum number of times
            n--;
        }
        return ans;
    }
};


