//Problem link - https://leetcode.com/problems/count-good-nodes-in-binary-tree/


//Approach 1 -> Using ans variable by reference

class Solution {
public:
    void solve(TreeNode *root,int maxi,int &ans)
    {
        if(!root) return;
        if(root->val>=maxi) ans++;
        solve(root->left,max(maxi,root->val),ans);
        solve(root->right,max(maxi,root->val),ans);
    }
    int goodNodes(TreeNode* root) {
        int ans = 0;
        solve(root,INT_MIN,ans);
        return ans;
    }
};

//Approach 2 -> Without using ans variable

class Solution {
public:
    int solve(TreeNode *root,int maxi)
    {
        if(!root) return 0;
        int left = solve(root->left,max(maxi,root->val));
        int right = solve(root->right,max(maxi,root->val));
       return left+right + (root->val>=maxi?1:0);
    }
    int goodNodes(TreeNode* root) 
    {
        return solve(root,INT_MIN);
    }
};
