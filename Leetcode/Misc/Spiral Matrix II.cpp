//Problem link - https://leetcode.com/problems/spiral-matrix-ii/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n));
        int currVal = 1;
        int sR = 0,sC = 0,eR = n-1,eC = n-1;//sR->Start Row, sC->Start Column, eR->End Row, eC->End Column
        while(sR<=eR && sC<=eC)
        {
            for(int i=sC;i<=eC;i++)//Traversing upper row from left to right
            {
                ans[sR][i] = currVal++;
            }
            sR++;//upper row has been traversed
            
            for(int i=sR;i<=eR;i++)//traversing right column from top to bottom
            {
                ans[i][eC] = currVal++;
            }
            eC--;//right column has been traversed
            
            for(int i=eC;i>=sC;i--)//traversing bottom row from right to left
            {
                ans[eR][i] = currVal++;
            }
            eR--;//bottom row has been traversed
            
            for(int i=eR;i>=sR;i--)//traversing left column from bottom to top
            {
                ans[i][sC] = currVal++;
            }
            sC++;//left column has been traversed
        }
        return ans;
    }
};
