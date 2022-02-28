//Problem link - https://leetcode.com/problems/inorder-successor-in-bst/
//Video link - https://www.youtube.com/watch?v=SXKAD2svfmI


class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode *succ = NULL;
        int key = p->val;
        while(root)
        {
            if(root->val>key)//answer will always be on right part so if we are going left then we might be missing ans
            {
                succ = root;//first store potential successor in succ
                root = root->left;
            }
            else
            {
                root = root->right;
            }
        }
        return succ;
    }
};
