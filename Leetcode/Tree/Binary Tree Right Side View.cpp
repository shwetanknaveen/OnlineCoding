//Problem link - https://leetcode.com/problems/binary-tree-right-side-view/

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        int size;
        TreeNode *temp;
        queue<TreeNode*> qu;
        if(!root) return ans;
        qu.push(root);
        while(!qu.empty())
        {
            size = qu.size();
            while(size--)
            {
                temp = qu.front();
                qu.pop();
                if(size==0) ans.push_back(temp->val);
                if(temp->left) qu.push(temp->left);
                if(temp->right) qu.push(temp->right);
            }
        }
        return ans;
    }
};
