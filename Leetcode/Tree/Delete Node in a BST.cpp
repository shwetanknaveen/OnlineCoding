//Problem link - https://leetcode.com/problems/delete-node-in-a-bst/
//Video link - https://www.youtube.com/watch?v=kouxiP_H5WE


//Iterative approach
class Solution {
public:
    TreeNode *deleteThis(TreeNode *root)//it will delete the node and then join it's right child to the rightmost child
    									//of left part
    {
        if(!root->left) return root->right;//if left child doesn't exist
        if(!root->right) return root->left;//if right child doesn't exist
        
        //both children of node to be deleted, exist 
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

//Recursive approach

class Solution {
public:
    int pred(TreeNode *root)
    {
        root = root->left;
        while(root->right)
            root = root->right;
        return root->val;
    }
    int succ(TreeNode *root)
    {
        root = root->right;
        while(root->left)
            root = root->left;
        return root->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        
        if(key>root->val) root->right = deleteNode(root->right,key);//has to be deleted from right part
        else if(key<root->val) root->left = deleteNode(root->left,key);//has to deleted from left part
        
        else//this is the node which has to be delted
        {
            if(!root->left && !root->right)//this node is leaf node
                root = NULL;//simply set it NULL as it will be returned NULL in the last and it's parent will now point to NULL
                			//This way it is different from linked list deletion issue when pointer to last node is given
            else if(root->right)//it has right child then it will have successor hence copy that value here and delete successor from right part
            {
                root->val = succ(root);
                root->right = deleteNode(root->right,root->val);
            }
            else//it has left child then it will have predecessor hence copy that value here and delete that predecessor from left part
            {
                root->val = pred(root);
                root->left = deleteNode(root->left,root->val);
            }
        }
        return root;
    }
};
