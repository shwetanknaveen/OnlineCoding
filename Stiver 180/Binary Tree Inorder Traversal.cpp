//Problem link - https://leetcode.com/problems/binary-tree-inorder-traversal/

//Approach 1 - Recursive approach

class Solution {
public:
    void solve(TreeNode *root,vector<int> &ans)
    {
        if(root)
        {
            solve(root->left,ans);
            ans.push_back(root->val);
            solve(root->right,ans);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        solve(root,ans);
        return ans;
    }
};

//Approach 2 - Iterative approach using stack

//Do null check before accessing any member of TreeNode*
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> stac;
        while(root || !stac.empty())//process untill this root is not null or there is some node on stack which can be processed
        {
            if(root && root->left)//if this root has left node then in inorder it has to be processed first
            {
                stac.push(root);//so push this root on stack for processing it later
                root = root->left;//and go on left
            }
            else//root doesn't have left or root is null
            {
                if(root)//if root is not null then add this in ans
                ans.push_back(root->val);
                if(root && root->right)//after pushing this value if there is something on right then we have to go there first
                    root = root->right;
                else if(!stac.empty())//if there is nothing on right or this root is null then we have to check nodes on stack
                {
                    ans.push_back(stac.top()->val);
                    root = stac.top()->right;//its left was visited now this is added in ans so now go on its right
                    stac.pop();
                }
                else//there is nothing in left nothing in right and nothing on stack then root has to be set null
                {
                    root = NULL;
                }
            }
        }
        return ans;
    }
};
