//Problem link - https://leetcode.com/problems/convert-bst-to-greater-tree/

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
 //Approach 1
class Solution {
public:
    void helper(TreeNode *root,int &sum)
    {
        if(!root) return;
        
        helper(root->right,sum);
        sum += root->val;//now control has returned from right part hence add this node value to sum upto here
        root->val = sum;//update this node's value with sum's value which has sum of all values greater than
                        //this node i.e., values of those node which are on right of it
        helper(root->left,sum);//now process the left part
    }
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        helper(root,sum);
        return root;
    }
};

//Approach 2
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
    void inorder(TreeNode *root,vector<TreeNode*> &in)
    {
        if(root)
        {
            inorder(root->left,in);
            in.push_back(root);
            inorder(root->right,in);
        }
    }
    TreeNode* convertBST(TreeNode* root) {
        vector<TreeNode*> in;
        inorder(root,in);
        int sum = 0;
        for(int i =in.size()-1;i>=0;i--)//start from the largest node to the smallest node
        {
            in[i]->val += sum;//add sum of larger nodes upto here to this node's value and store
            sum = in[i]->val;//now store the new sum into sum
        }
        return root;
    }
};
