//Problem link - https://leetcode.com/problems/binary-tree-pruning/

class Solution {
public:
    TreeNode* pruneTree(TreeNode* root)     
	{
        if(!root) return root;
        //Solve first left and right subtree in postorder
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        return (root->val==1 || root->left || root->right)?root:NULL;
        /*
        This subtree will be included if this node itself is 1 or one of its child subtree has one (in that case that child
        subtree won't be NULL)
        */
    }
};
