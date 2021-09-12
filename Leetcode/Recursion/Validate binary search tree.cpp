//Question link - https://leetcode.com/problems/validate-binary-search-tree/submissions/

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
    bool utilityRec(TreeNode *node,int max,int min)
    {
        if(!node) return true;//if node doesn't exist then obviously it won't violate BST condition
        
        if(node->val > max || node->val < min)//TRICK- Here we think first mainly from negative                                                     case point of view
        return false;                           //i.e., in what condition the BST condition                                                     will fail
        
        else 
        {
            long long int newMax = node->val;
            newMax = newMax-1;//going on left subtree, nodes can have max value atmost current node's value -1
            long long int newMin = node->val;
            newMin = newMin+1;//going on right subtree, nodes can have min value atmost current node's value + 1
            return (utilityRec(node->left,newMax,min) && utilityRec(node->right,max,newMin));
            
            /*Simply passsing changed newMax and newMin as-
			return (utilityRec(node->left,node->val-1,min) && utilityRec(node->right,max,node->val+1));
			caused INTEGER overflow because although our min and max are long long int because node->val and 1 are both
			integers hence overflow happens before they get assigned to min or max
			*/
        }
    }
    bool isValidBST(TreeNode* root) {
       return utilityRec(root,INT_MAX,INT_MIN);
    }
};
