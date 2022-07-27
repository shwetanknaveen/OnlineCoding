//Problem link - https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/

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
    void trav(TreeNode *root,int &cumSum)
    {
        if(!root) return;
        trav(root->right,cumSum);//Go to right first
        cumSum += root->val;//when returning from right accumulate the cummulative sum of larger values
        root->val = cumSum;//update the value of this node with cummulative sum
        trav(root->left,cumSum);//no go on left side for processing
    }
    TreeNode* bstToGst(TreeNode* root) {
        int cumSum = 0;
        trav(root,cumSum);
        return root;
    }
};
