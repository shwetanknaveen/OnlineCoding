//Problem link - https://leetcode.com/problems/increasing-order-search-tree/

class Solution {
public:
    void inorder(TreeNode *root,vector<TreeNode*> &in)
        {
        if(root)
            {
            inorder(root->left,in);
            in.push_back(root);
            inorder(root->right,in);
            }
        }
    TreeNode* increasingBST(TreeNode* root) {
        vector<TreeNode*> in;
        inorder(root,in);
        for(int i=0;i<in.size()-1;i++)
            {
            in[i]->left = NULL;//makeing the left most node as root and making its left pointer as NULL
            in[i]->right = in[i+1];
            }
        if(!root) return NULL;
        in[in.size()-1]->left = in[in.size()-1]->right = NULL;//Last node's left and right should be NULL
        return in[0];//New root will be the left most node of the tree
    }
};
