//Problem link - https://leetcode.com/problems/binary-tree-maximum-path-sum/
//Video link - https://www.youtube.com/watch?v=Osz-Vwer6rw&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=48

//Minor modification from the concept of following question
//Problem link -> https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1#
//Video link -> https://www.youtube.com/watch?v=zmPj_Ee3B8c&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=47
class Solution {
public:
    int solve(TreeNode *root,int &res,map<TreeNode*,int> &dp)
    {
        if(!root) return 0;//if no root then no value of node in the chain of max sum
        
        if(dp.find(root) != dp.end()) return dp[root];
        int l = solve(root->left,res,dp);//max sum of nodes for left part
        int r = solve(root->right,res,dp);//max sum of nodes for right part
        
        int maxOfLR = max(l,r);
        if(maxOfLR<0) maxOfLR = 0;//if best of both part don't give a positive value then leave those parts as here we have
        						//option that we may start from any node and end at any node. Ending nodes of the path need
        						//not be leaf node
        int temp = root->val+maxOfLR;//here root is not assumed the turning node i.e., the top node of max sum path hence it propogates
        					//the maximum sum including iteself upawards
        res = max(res,root->val+l+r);//result stores the best value among the previous value and if this root is taken as top
        					//node of max sum path
        
        return dp[root] = (temp>0?temp:0);//if temp can't propagate positive value then return 0 from temp
    }
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        map<TreeNode*,int> dp;
        solve(root,res,dp);//solve won't return the answer but in solve funtion we will store the answer
        return res;
    }
};
