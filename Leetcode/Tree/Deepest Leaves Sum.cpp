//Problem link - https://leetcode.com/problems/deepest-leaves-sum/

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
    int deepestLeavesSum(TreeNode* root) {
        int lastSum = 0;
        if(!root) return 0;
        queue<TreeNode*> qu;
        TreeNode *thisNode;
        qu.push(root);
        while(!qu.empty())
        {
            int size = qu.size(),sum = 0;
            while(size--)
            {
                thisNode = qu.front();
                qu.pop();
                if(thisNode->left) qu.push(thisNode->left);
                if(thisNode->right) qu.push(thisNode->right);
                
                sum += thisNode->val;
            }
            lastSum = sum;
        }
        return lastSum;
    }
};
