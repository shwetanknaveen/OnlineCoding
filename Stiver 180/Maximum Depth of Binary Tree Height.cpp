//Problem link - https://leetcode.com/problems/maximum-depth-of-binary-tree/
//Video link - https://www.youtube.com/watch?v=eD3tmO66aBA


//Approach 1 Recursive solution DFS
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        return max(1+maxDepth(root->left),1+maxDepth(root->right));
    }
};

//Approach 2 Level Order traversal BFS
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> qu;
        TreeNode *temp;
        int height = 0,size;
        qu.push(root);
        while(!qu.empty())
        {
            height++;
            size = qu.size();
            while(size--)
            {
                temp = qu.front();
                qu.pop();
                if(temp->left) qu.push(temp->left);
                if(temp->right) qu.push(temp->right);
            }
        }
        return height;
    }
};
