//Problem link - https://leetcode.com/problems/rotate-image/submissions/
//Video link - https://www.youtube.com/watch?v=Y72QeX0Efxw&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=13

/*
Algorithm is to take transpose and then reverse each row
Time complexity->O(n^2)
Space complexity->O(1)
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)//note that we go only before i in each row for transpose
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<n;i++)
        {
            reverse(matrix[i].begin(),matrix[i].end());//reversing each row
        }
    }
};
