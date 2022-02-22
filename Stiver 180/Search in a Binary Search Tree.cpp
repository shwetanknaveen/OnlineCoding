//Problem link - https://leetcode.com/problems/search-in-a-binary-search-tree/

//Approach 1 Recursive Approach
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return NULL;
        if(val==root->val) return root;
        if(val<root->val) return searchBST(root->left,val);
        else return searchBST(root->right,val);
    }
};

//Approach 2 Iterative approach
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root)
        {
            if(root->val==val)
                break;
            if(root->val<val)
                root=root->right;
            else root = root->left;
        }
        return root;
    }
};
