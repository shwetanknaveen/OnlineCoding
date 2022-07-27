//Problem link - https://leetcode.com/problems/equal-row-and-column-pairs/

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        multiset<vector<int>> rows;
        for(auto row:grid)
            rows.insert(row);
        int ans = 0;
        for(int j=0;j<grid[0].size();j++)
        {
            vector<int> col;
            for(int i=0;i<grid.size();i++)
                col.push_back(grid[i][j]);
            if(rows.find(col)!=rows.end()) ans += rows.count(col);
        }
        return ans;
    }
};
