//Problem link - https://leetcode.com/problems/binary-tree-level-order-traversal/
//Video link - https://www.youtube.com/watch?v=EoAsWbO7sqg

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> qu;
        TreeNode *temp;
        qu.push(root);
        int size;
        while(!qu.empty())
        {
            vector<int> thisLevel;
            size = qu.size();
            while(size--)
            {
                temp = qu.front();
                qu.pop();
                thisLevel.push_back(temp->val);
                if(temp->left) qu.push(temp->left);
                if(temp->right) qu.push(temp->right);
            }
            ans.push_back(thisLevel);
        }
        return ans;
    }
};
