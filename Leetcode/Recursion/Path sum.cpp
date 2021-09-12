//Problem link- https://leetcode.com/problems/path-sum/submissions/
//It is little different from same question on GFG, here it wants ans as false if tree is empty
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    public: 
        bool hasPathSum(TreeNode *root, int targetSum) {
        
        if(!root) return false;
        
        if(root->right==NULL && root->left==NULL && targetSum -root->val==0 )  return true;
        
        return  hasPathSum(root->left, targetSum -root->val)||hasPathSum(root->right, targetSum -root->val);
        
    }
};
