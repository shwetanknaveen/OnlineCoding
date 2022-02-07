//Problem link - https://leetcode.com/problems/binary-tree-preorder-traversal/

//Approach 1 -> Recursive approach
class Solution {
public:
    void solve(TreeNode *root,vector<int> &ans)
    {
        if(root)
        {
            ans.push_back(root->val);
            solve(root->left,ans);
            solve(root->right,ans);
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        solve(root,ans);
        return ans;
    }
};

//Approach 2 -> Iterative approach using stack

//Do null check before accessing any member of TreeNode*
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> stac;
        vector<int> ans;
        while(root || !stac.empty())//process untill this root is not null or there is some node on stack which can be processed
        {
            if(root)
            ans.push_back(root->val);//in preorder,root val is pushed first then left then right
            if(root && root->right)//if this root has right child then it will be processed later hence put it on stack
                stac.push(root->right);
            if(root && root->left)//if it has left child then go on to process it first
                root = root->left;
            else//if root has no left child then its right child should be processed now which if exist must be on top of stack
            {
                if(!stac.empty())
                {
                    root = stac.top();
                    stac.pop();
                }
                else //root has no left child and no right child(nothing on stack) then now root will also be null as there
                	//is nothing further to process
                    root = NULL;
            }
        }
        return ans;
    }
};
