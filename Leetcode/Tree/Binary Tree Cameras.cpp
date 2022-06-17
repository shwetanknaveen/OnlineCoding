//Problem link - https://leetcode.com/problems/binary-tree-cameras/

class Solution {
public:
    void postOrder(TreeNode *root,TreeNode *par,unordered_set<TreeNode*> &covered,int &ans)
    {
        if(root)
        {
            postOrder(root->left,root,covered,ans);
            postOrder(root->right,root,covered,ans);
            //We are checking from bottom to up, so if any of the left or right child is not covered
            //we fit camera at this node so that its children get covered
            if((!par && !covered.count(root)) || !covered.count(root->left) || !covered.count(root->right))
            {
                //If we fit camera at this node then all the 4 nodes (node itself,its parent and both children) will be covered
                covered.insert(par);
                covered.insert(root);
                covered.insert(root->left);
                covered.insert(root->right);
                ans++;
            }
        }
    }
    int minCameraCover(TreeNode* root) {
        int ans = 0;
        unordered_set<TreeNode*> covered;
        covered.insert(NULL);//For leaf nodes, make its children covered
        postOrder(root,NULL,covered,ans);
        return ans;
        
    }
};
