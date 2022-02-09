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

//Approach 2 - Iterative approach using stack =>Best iterative approach

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


//Approach 3 Iterative apporach using bool value when node being push on stack to remember that whether its righ child has
//been covered or not

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<pair<TreeNode*,bool>> stac;// <node,right child covered or not>
        vector<int> ans;
        while(root || !stac.empty())
        {
            if(root && root->left)
            {
                stac.push(make_pair(root,false));//push this node without its right child being covered
                root = root->left;
            }
            else if(root && root->right)//only right child which is covered right now
            {
                stac.push(make_pair(root,true));
                root = root->right;
            }
            else//no left or right child or root is null
            {
                if(root)
                    ans.push_back(root->val);
                if(!stac.empty())
                {
                    auto p = stac.top();
                    stac.pop();
                    if(p.second==false)//right part wasn't covered
                    {
                        root = p.first->right;//now go to right
                        stac.push(make_pair(p.first,true));//push it again on the stack as use it when returning after
                        									//processing the right child too
                    }
                    else//right part was covered
                    {
                        ans.push_back(p.first->val);//push this node value and no need to push it back again
                        root = NULL;//in next iteration, root itself will assign approptiate value from stack if it's not empty
                    }
                }
                else//root is null and stack is also empty
                {
                    root = NULL;
                }
            }
        }
        return ans;
    }
};

//Approach 4 - Morris Traversal
//T(n) = O(n)	S(n) = O(1)
//Video link - https://www.youtube.com/watch?v=80Zug6D1_r4

//We will modify the preorder morris traversal from root->left->right to root->right->left. For this we need to do one more
//change. While in normal preorder and inorder, we were creating thread from right most node of left subtree to present
//node, here we will create thread from left most node of right subtree to present node as here we have to cover
//right subtree before left subtree

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        while(root)
        {
            TreeNode *curr = root;//We will create thread from left most node of right subtree to present node and will
            						//travell to that node using curr
            if(curr->right)//if root has right child
            			//We can't push directly this root node val to ans as we are not sure whether we are here
            			//thorough thread link after covering right subtree or we are here for the first time
            {
                curr = curr->right;
                while(curr->left && curr->left != root)//go to left most node of right subtree
                    curr=curr->left;
                if(curr->left != root)//not threaded yet
                {
                    ans.push_back(root->val);//it means root was visited for first time and this is modified preorder hence 
                    						//push this node's val to ans
                    curr->left = root;//create the thread
                    root = root->right;//go to right to cover right subtree as modified preorder is root->right->left
                }
                else//was threaded
                {
                    curr->left = NULL;//break the thread
                    root = root->left;//right subtree has been covered hence now cover the left one
                    					//no need to push this node value as we are here for the second time using thread
                    					//link
                }
            }
            else//root hasn't right child
            {
                ans.push_back(root->val);//modified preorder is root->right->left hence push this value before going to left
                root = root->left;
            }
        }
        reverse(ans.begin(),ans.end());//reversing root->right->left to left->right->root to make it post order
        return ans;
    }
}; 
