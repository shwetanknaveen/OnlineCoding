//Problem link - https://leetcode.com/problems/valid-boomerang/

class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        return (points[0][1]-points[1][1])*(points[1][0]-points[2][0]) != (points[1][1]-points[2][1])*(points[0][0]-points[1][0]);
        
        /*
        If we compute m12 and m13 seperately then there can be issue of division by 0 hence we do cross multiplication as above
        m12 = double(points[0][1]-points[1][1])/double(points[0][0]-points[1][0]);
        m23 = double(points[1][1]-points[2][1])/double(points[1][0]-points[2][0]);
        return (m12 != m23);
        */
    }
};
