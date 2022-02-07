//Problem link - https://leetcode.com/problems/binary-tree-postorder-traversal/

//Approach 1 - Recursive approach

class Solution {
public:
    void solve(TreeNode *root,vector<int> &ans)
    {
        if(root)
        {
            solve(root->left,ans);
            solve(root->right,ans);
            ans.push_back(root->val);
        }
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        solve(root,ans);
        return ans;
    }
};

//Approach 2 - Iterative approach using stack

//Normally preorder traversal is root->left->right so if we make it root->right->left and then reverse it (left->right->root)
//,it becomes post order traversal. Hence we will modify preorder traversal and then reverse the result

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> stac;
        vector<int> ans;
        while(root || !stac.empty())//process untill this root is not null or there is some node on stack which can be processed
        {
            if(root)
            ans.push_back(root->val);//in modified preorder,root val is pushed first then right then left
            if(root && root->left)//if this root has left child then it will be processed later hence put it on stack
                stac.push(root->left);
            if(root && root->right)//if it has right child then go on to process it first
                root = root->right;
            else//if root has no right child then its left child should be processed now which if exist must be on top of stack
            {
                if(!stac.empty())
                {
                    root = stac.top();
                    stac.pop();
                }
                else //root has no right child and no left child(nothing on stack) then now root will also be null as there
                	//is nothing further to process
                    root = NULL;
            }
        }
        reverse(ans.begin(),ans.end());//reversing root->right->left 	to	left->right->root
        return ans;
    }
};
