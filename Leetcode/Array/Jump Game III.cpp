//Problem link - https://leetcode.com/problems/jump-game-iii/

class Solution {
public:
    bool check(vector<int> &arr,int ind,vector<bool> &vis)
    {
        int n = arr.size();
        if(arr[ind]==0) return true;//destination reached
        vis[ind] = true;
        bool left,right;
        left = right = false;
        int leftJump = ind-arr[ind], rightJump = ind+arr[ind];
        if(leftJump>=0 && !vis[leftJump]) left = check(arr,leftJump,vis);//if it can jump on left and that left jump index hasn't been explored yet
        if(rightJump<n && !vis[rightJump]) right = check(arr,rightJump,vis);//if it can jump on right and that right jump index hasn't been explored yet
        return left || right;
    }
    bool canReach(vector<int>& arr, int start) 
    {
        vector<bool> vis(arr.size(),false);
        return check(arr,start,vis);
    }
};
