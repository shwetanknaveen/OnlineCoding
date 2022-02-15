//Problem link - https://leetcode.com/problems/balanced-binary-tree/
//Video link - https://www.youtube.com/watch?v=Yt50Jfbd8Po

//Approach 1
//Time complexity = O(n^2)
//Space complexity = O(n)	for skew trees
class Solution {
public:
    int height(TreeNode *root)
    {
        if(!root) return 0;
        else return (1+max(height(root->left),height(root->right)));
    }
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        if(abs(height(root->left)-height(root->right))<=1)
            return isBalanced(root->left)&&isBalanced(root->right);
        else return false;
    }
};

//Approach 2
//Time complexity = O(n)
//Returning -1 will mean that tree starting from this node is not balanced
class Solution {
public:
    int changHeightFun(TreeNode *root)
    {
        if(!root) return 0;
        
        int lh = changHeightFun(root->left);
        int rh = changHeightFun(root->right);
        
        if(lh==-1 || rh==-1) return -1;//if any of left or right subtree is not balanced then this tree also won't be balanced
        if(abs(lh-rh)>1) return -1;//if height difference at this node is greater than 1 then tree is not balanced
        
        return max(1+lh,1+rh);//if tree at this node is balanced then return the usual height
    }
    bool isBalanced(TreeNode* root) {
        return changHeightFun(root)==-1?false:true;
    }
};
