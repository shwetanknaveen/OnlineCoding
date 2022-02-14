//Problem link - https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

//Approach 1 - Using normal level order traversal and fliping the result alternately at each level
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> qu;
        TreeNode *temp;
        qu.push(root);
        int size;
        bool rev = false;
        while(!qu.empty())
        {
            vector<int> thisLevel;
            size = qu.size();
            while(size--)
            {
                temp = qu.front();
                qu.pop();
                thisLevel.push_back(temp->val);
                if(temp->left) qu.push(temp->left);
                if(temp->right) qu.push(temp->right);
            }
            if(rev) reverse(thisLevel.begin(),thisLevel.end());
            rev = !rev;
            ans.push_back(thisLevel);
        }
        return ans;
    }
};

//Approach 2 -> Using two stacks =>Spiral order traversal in GFG/Must Do for Adobe

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        stack<TreeNode*> stack1,stack2;
        TreeNode *temp;
        int size;
        stack1.push(root);
        bool flag = true;
        //When we will be popping from stack1 then we will be pushing to stack2 and vice versa
        while(!stack1.empty() || !stack2.empty())
        {
            if(flag)//initially flag is true and root is on stack1
                size = stack1.size();
            else size = stack2.size();
            vector<int> thisLine;
            while(size--)
            {
                if(flag)//initially flag is true and root is on stack1 hence we need to pop from there and push on stack2
                {
                    temp = stack1.top();
                    stack1.pop();
                    thisLine.push_back(temp->val);
                    if(temp->left) stack2.push(temp->left);//in next line right child has to come first hence push it later
                    if(temp->right) stack2.push(temp->right);//as stack follow LIFO order
                }
                else
                {
                    temp = stack2.top();
                    stack2.pop();
                    thisLine.push_back(temp->val);
                    if(temp->right) stack1.push(temp->right);//in next line left child has to come first hence push it later
                    if(temp->left) stack1.push(temp->left);//as stack follow LIFO order
                }
            }
            flag = !flag;
            ans.push_back(thisLine);
        }
        return ans;
    }
};
