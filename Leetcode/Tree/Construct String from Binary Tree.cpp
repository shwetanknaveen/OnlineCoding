//Problem link - https://leetcode.com/problems/construct-string-from-binary-tree/

class Solution {
public:
    string ans;
    void solve(TreeNode *root)
    {
        if(!root) return;
        ans += "("+to_string(root->val);//put ( and val when we first visit the node
        if(!root->left && root->right) ans += "()";//if this node has no left child but right child then we put () for left 
        											//child
		solve(root->left);
        solve(root->right);
        ans += ")";//close parenthesis in post order manner
    }
    string tree2str(TreeNode* root) {
        if(!root) return ans;
        solve(root);
        ans = ans.substr(1,ans.length()-2);//trim end brackets
        return ans;
    }
};
