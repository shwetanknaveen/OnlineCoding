//Problem link - https://leetcode.com/problems/symmetric-tree/

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
    bool helper(TreeNode *left, TreeNode *right)
    {
        if(!left && !right) return true;//if both don't exist then obviously symmetric
        if((!left && right) || (left && !right)) return false;//if one exist and other doesn't then not symmetric
        if(left->val != right->val) return false;//if left and right value don't match then not symmetric
        
		return (helper(left->right,right->left) && helper(left->left,right->right));//now left's right value has to be 
		//compared with right's left and left's left value has to be compared with right's right
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return helper(root->left,root->right);//will compare left and right part
    }
};
