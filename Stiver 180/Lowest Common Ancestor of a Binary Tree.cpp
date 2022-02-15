//Problem link - https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
//Video link - https://www.youtube.com/watch?v=_-QHfMDde90

//Approach 1->Brute force ->If two search nodes are on the same side of subtree of this node then seach for LCA on that side 
//otherwise return this node as LCA
//Time complexity = O(n^2)
class Solution {
public:
    bool preorder(TreeNode *root,TreeNode *search)//search for the node "search" in tree starting from root
    {
        if(root)
        {
            if(root==search)
                return true;//node found
            else return preorder(root->left,search)||preorder(root->right,search);//search on left and right half
        }
        else return false;//node not found
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(preorder(root->left,p)&&preorder(root->left,q))//both p and q are on left subtree of this node
            return lowestCommonAncestor(root->left,p,q);
        else if(preorder(root->right,p)&&preorder(root->right,q))//both p and q are on right subtree of this node
            return lowestCommonAncestor(root->right,p,q);
        else //this node itself is LCA
            return root;
    }
};

//Approach 2 ->Do single traversal to all nodes. See the video for better clarification
//Time complexity = O(n)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        if(root==p || root==q) return root;//found on of the nodes being searched
        TreeNode *left = lowestCommonAncestor(root->left,p,q);
        TreeNode *right = lowestCommonAncestor(root->right,p,q);
        
        if(!left) return right;//left is NULL then return the right
        if(!right) return left;//right is NULL then reutrn the left
        
        return root;//both left and right are not NULL hence both p ans q are on opposite side of subtress of this node and 
        			//this node is our LCA
    }
};
