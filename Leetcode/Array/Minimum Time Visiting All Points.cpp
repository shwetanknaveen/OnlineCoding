//Problem link - https://leetcode.com/problems/minimum-time-visiting-all-points/

//See "Interviewbit/Min Steps in Infinite Grid"

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        for(int i=1;i<points.size();i++)
        {
            int delX = abs(points[i][0]-points[i-1][0]);
            int delY = abs(points[i][1]-points[i-1][1]);
            ans += max(delX,delY);
        }
        return ans;
        }
};
