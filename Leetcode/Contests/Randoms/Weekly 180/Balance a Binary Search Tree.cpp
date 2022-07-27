//Problem link - https://leetcode.com/problems/balance-a-binary-search-tree/

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
    void inorder(TreeNode *root,vector<int> &allVals)
    {
        if(root)
        {
            inorder(root->left,allVals);
            allVals.push_back(root->val);
            inorder(root->right,allVals);
        }
    }
    TreeNode *construct(vector<int> &allVals,int start,int end)
    {
        if(start>end) return NULL;
        int mid = start + (end-start)/2;
        TreeNode *root = new TreeNode(allVals[mid]);
        root->left = construct(allVals,start,mid-1);
        root->right = construct(allVals,mid+1,end);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> allVals;
        inorder(root,allVals);
        return construct(allVals,0,allVals.size()-1);
    }
};
