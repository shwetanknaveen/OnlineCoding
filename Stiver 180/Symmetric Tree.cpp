//Problem link - https://leetcode.com/problems/symmetric-tree/

class Solution {
public:
    bool helper(TreeNode *left,TreeNode *right)
    {
        if(!left || !right)
            return left==right;//if any of left and right is NULL then both should be NULL for tree to be symmetric
        
        if(left->val != right->val)//if values don't match then tree is not symmetric
            return false;
        
        return helper(left->left,right->right)&&helper(left->right,right->left);//values on above level matched then we go down
        																		//for checking in this manner
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return helper(root->left,root->right);
    }
};
