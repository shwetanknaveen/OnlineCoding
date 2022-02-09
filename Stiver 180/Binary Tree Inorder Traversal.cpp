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

//Approach 3 - Morris Traversal
//T(n) = O(n)	S(n) = O(1)
//Video link - https://www.youtube.com/watch?v=80Zug6D1_r4
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        while(root)
        {
            TreeNode *curr = root;//We will create thread from right most node of left subtree to present node and will
            						//travell to that node using curr
            if(curr->left)//if root has left child
            			//We can't push directly this root node val to ans as we are not sure whether we are here
            			//thorough thread link after covering left subtree or we are here for the first time
            {
                curr = curr->left;
                while(curr->right && curr->right != root)//go to right most node of left subtree
                    curr=curr->right;
                if(curr->right != root)//not threaded yet
                {
                    curr->right = root;//create the thread
                    root = root->left;//go to left to cover left subtree as inorder is left->root->right
                    //no need to push node's value here as it is visited for the first time
                }
                else//was threaded
                {
                    curr->right = NULL;//break the thread
                    ans.push_back(root->val);//visiting the node for second time hence push the node value to ans as
											//in inorder it is left->root->right                    		
                    root = root->right;//left subtree has been covered hence now cover the right one
                    
                    					
                }
            }
            else//root hasn't left child
            {
                ans.push_back(root->val);//inorder is left->root->right hence push this value before going to right
                root = root->right;
            }
        }
        return ans;
    }
};
