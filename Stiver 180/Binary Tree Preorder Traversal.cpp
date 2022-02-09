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

//Approach 3 - Morris Traversal
//T(n) = O(n)	S(n) = O(1)
//Video link - https://www.youtube.com/watch?v=80Zug6D1_r4
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
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
                    ans.push_back(root->val);//it means root was visited for first time and this is preorder hence push this
                    						//node's val to ans
                    curr->right = root;//create the thread
                    root = root->left;//go to left to cover left subtree as preorder is root->left->right
                }
                else//was threaded
                {
                    curr->right = NULL;//break the thread
                    root = root->right;//left subtree has been covered hence now cover the right one
                    					//no need to push this node value as we are here for the second time using thread
                    					//link
                }
            }
            else//root hasn't left child
            {
                ans.push_back(root->val);//preorder is root->left->right hence push this value before going to right
                root = root->right;
            }
        }
        return ans;
    }
};
