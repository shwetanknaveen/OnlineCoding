//Problem link - https://leetcode.com/problems/flood-fill/
class Solution {
public:
    void floodIt(vector<vector<int>> &image,int i,int j,int oldSrcColor,int newColor)
    {
        if(i<0 || i>=image.size() || j<0 || j>=image[0].size() || image[i][j] != oldSrcColor)
            return;//if this cell is out of bound or has no matching with old color of source cell
                    //then its color can't be changed and it can't propogate newColor
        
        image[i][j] = newColor;
        floodIt(image,i-1,j,oldSrcColor,newColor);
        floodIt(image,i+1,j,oldSrcColor,newColor);
        floodIt(image,i,j-1,oldSrcColor,newColor);
        floodIt(image,i,j+1,oldSrcColor,newColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(newColor == image[sr][sc]) return image;//if newColor is same as old color at source cell then propogation of
													//newColor won't make any difference 
        floodIt(image,sr,sc,image[sr][sc],newColor);
        return image;
    }
};
