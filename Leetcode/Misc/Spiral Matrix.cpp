//Problem link - https://leetcode.com/problems/spiral-matrix/
//See "Leetcode/Misc/Spiral Matrix II". There matrix has to be a square matrix but here it can be rectangular also so that 
//normal condition in while doesn't work


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int row = matrix.size(), cols = matrix[0].size();
        int sR = 0,sC = 0,eR = row-1,eC = cols-1;
        int nElements = row * cols;
        int count = 0;
        while(1)
        {
            for(int i=sC;i<=eC;i++)
            {
                ans.push_back(matrix[sR][i]);
                count++;
            }
            sR++;
            if(count==nElements) break;
            
            for(int i=sR;i<=eR;i++)
            {
                ans.push_back(matrix[i][eC]);
                count++;
            }
            eC--;
            if(count==nElements) break;
            
            for(int i=eC;i>=sC;i--)
            {
                ans.push_back(matrix[eR][i]);
                count++;
            }
            eR--;
            if(count==nElements) break;
            
            for(int i=eR;i>=sR;i--)
            {
                ans.push_back(matrix[i][sC]);
                count++;
            }
            sC++;
            if(count==nElements) break;
        }
        return ans;
    }
};

//Another way without keeping count
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int sR = 0,sC = 0,eR = matrix.size()-1,eC = matrix[0].size()-1;
        while(sR<=eR && sC<=eC)
        {
            for(int i=sC;i<=eC;i++)
            {
                ans.push_back(matrix[sR][i]);
            }
            sR++;
            if(sR>eR)
                break;
            for(int i=sR;i<=eR;i++)
            {
                ans.push_back(matrix[i][eC]);
            }
            eC--;
            if(sC>eC)
                break;
            
            for(int i=eC;i>=sC;i--)
            {
                ans.push_back(matrix[eR][i]);
            }
            eR--;
            
            for(int i=eR;i>=sR;i--)
            {
                ans.push_back(matrix[i][sC]);
            }
            sC++;
        }
        return ans;
    }
};
