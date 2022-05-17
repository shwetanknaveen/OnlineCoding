//Problem link - https://leetcode.com/problems/largest-triangle-area/

class Solution {
public:
    double getArea(vector<int> &p1,vector<int> &p2,vector<int> &p3)
    {
        double ans = 0.5;
        return ans*abs((p2[0]-p1[0])*(p3[1]-p1[1])-(p2[1]-p1[1])*(p3[0]-p1[0]));
        
    }
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double ans = 0.0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                for(int k=j+1;k<n;k++)
                    ans= max(ans,getArea(points[i],points[j],points[k]));
            }
        }
        return ans;
    }
};
