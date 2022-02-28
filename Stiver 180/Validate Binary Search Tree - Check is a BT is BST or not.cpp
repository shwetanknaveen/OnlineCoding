//Problem link - https://leetcode.com/problems/validate-binary-search-tree/
//Video link - https://www.youtube.com/watch?v=f-sj7I5oXEI&feature=youtu.be

class Solution {
public:
    bool recHelper(TreeNode* root,int max,int min)
    {
        if(!root)//empty node doesn't violate BST property 
            return true;
        
        if(root->val>max || root->val<min)//if root value is greater than max value or less than min value then 
            return false;					//it violates BST property hence return false
        
        if(root->val==INT_MIN)//if node value is INT_MIN
        {
            if(root->left) return false;//We can't go left as we can't afford value less than INT_MIN
            else return recHelper(root->right,max,root->val+1);//if there is no left child then we can go usual way to right
																//subtree 
        	//We can't leave this else case for default case otherwise there, while checking for left subtree, it will try
        	//to store INT_MIN-1 in int which will cause overflow
		}
        
        if(root->val==INT_MAX)//if node value is INT_MAX
        {
            if(root->right) return false;//We can't go right as we can't afford value greater than INT_MAX
            else return recHelper(root->left,root->val-1,min);//if there is no right child then we can go usual way to left
            												//subtree
            												
            //We can't leave this else case for default case otherwise there, while checking for right subtree, it will try
        	//to store INT_MAX+1 in int which will cause overflow
        }
        
        return recHelper(root->left,root->val-1,min) && recHelper(root->right,max,root->val+1);
        	//The default case to check both subtrees for BST property
    }
    bool isValidBST(TreeNode* root) {
        return recHelper(root,INT_MAX,INT_MIN);//initially max value can be INT_MAX and min value can be INT_MIN
    }
};
