//Problem link - https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
//Video link - https://www.youtube.com/watch?v=cX_kPV_foZc&feature=youtu.be

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    	
    	//if this node's value lies between values of given nodes or it is equal to one of them then this node is LCA of p and q
        if(root->val>=min(p->val,q->val) && root->val<=max(p->val,q->val))
            return root;
        if(root->val<min(p->val,q->val))//if this node value is less than both p and q's val then p and q both must be on right
            return lowestCommonAncestor(root->right,p,q);//side of this node
        else return lowestCommonAncestor(root->left,p,q);//both p and q must be on left side of this node
    }
};

//Iterative must better code

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int minVal = min(p->val,q->val),maxVal = max(p->val,q->val);
        while(root)
        {
            if(root->val<minVal)
                root = root->right;//both values are on right of current node
            else if(root->val>maxVal)
                root = root->left;//both values are on left of current node
            else
                break;//this node is LCA of p and q
        }
        return root;
    }
};
