//Problem link - https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
//Video link - https://www.youtube.com/watch?v=aZNaLrVebKQ

class Solution {
public:
    TreeNode* helper(int preStart,int preEnd,int inStart,int inEnd,vector<int> &pre,vector<int> &in,map<int,int> &inHash)
    {
        if(preStart>preEnd || inStart>inEnd)
            return NULL;
        TreeNode *root = new TreeNode(pre[preStart]);
        int indRoot = inHash[root->val];
        int numsOnLeft = inHash[root->val]-inStart;
        root->left = helper(preStart+1,preStart+numsOnLeft,inStart,indRoot-1,pre,in,inHash);
        				//preorder of left part starts one head from where it started and ends after covering all elements on left part
        				//inOrder of left starts from where it started and ends one before the index of root
        
        root->right = helper(preStart+numsOnLeft+1,preEnd,indRoot+1,inEnd,pre,in,inHash);
        				//preorder of right part starts one head from where preorder of left part ended and ends where it was originally ending
        				//inOrder of right starts one head of root and ends where it was ending
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> inHash;
        int end = inorder.size();
        for(int i=0;i<end;i++)
        {
            inHash[inorder[i]] = i;
        }
        return helper(0,end-1,0,end-1,preorder,inorder,inHash);
    }
};
