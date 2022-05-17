//Problem link - https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) 
    {
        if(original)
        {
            if(original == target) return cloned;//if this is the node which we are searching for then return the cloned node for this node
            TreeNode *leftSearch = getTargetCopy(original->left,cloned->left,target);//search in left part of tree and move left simultaneously
            																		//in cloned tree also
            TreeNode *rightSearch = getTargetCopy(original->right,cloned->right,target);//search in right part of tree and move right simultaneously
            																		//in cloned tree also
            
            return leftSearch!=NULL ? leftSearch : rightSearch;//if left part contains the desired node then return search result of left part
            												//otherwise return search result of right part
        }
        return NULL;//can't process this node
    }
};
