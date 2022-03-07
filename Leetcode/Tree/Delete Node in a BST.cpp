//Problem link - https://leetcode.com/problems/delete-node-in-a-bst/
//Video link - https://www.youtube.com/watch?v=kouxiP_H5WE

class Solution {
public:
    TreeNode *deleteThis(TreeNode *root)//it will delete the node and then join it's right child to the rightmost child
    									//of left part
    {
        if(!root->left) return root->right;//if left child doesn't exist
        if(!root->right) return root->left;//if right child doesn't exist
        
        //both children of node to be deleted exist 
        TreeNode *rightChild = root->right;
        TreeNode *leftChild = root->left;
        TreeNode *rightMostChildOfLeftPart = leftChild;
        while(rightMostChildOfLeftPart->right)
            rightMostChildOfLeftPart = rightMostChildOfLeftPart->right;
        
        rightMostChildOfLeftPart->right = rightChild;
        
        return leftChild;//now node got deleted and its right child got attached to rightmost child of left part hence
        				//leftChild has to be returned in place of node which was to be deleted
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        if(root->val==key)//if root itself has to be deleted
        {
            return deleteThis(root);
        }
        
        TreeNode *rootHolder = root;
        while(root)
        {
            if(root->val > key )//We should look left for smaller values in order to find key
            {
                if(root->left && root->left->val == key)
                {
                    root->left = deleteThis(root->left);
                    break;
                }
                else 
                {
                    root = root->left;
                }
            }
            else//We should look right for larger values in order to find key
			//root->val<key =>Equal condition has already been handled and now we are looking one step down-ahead
            {
                if(root->right && root->right->val == key)
                {
                    root->right = deleteThis(root->right);
                    break;
                }
                else
                {
                    root = root->right;
                }
            }
        }
        return rootHolder;
    }
};
