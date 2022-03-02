//Problem link - https://leetcode.com/problems/kth-smallest-element-in-a-bst/
//Video link - https://www.youtube.com/watch?v=9TJYWh0adfk&feature=youtu.be

class Solution {
public:
    void getAns(TreeNode *root,int &k,int &ans)
    {
        if(root)
        {
            getAns(root->left,k,ans);
            if(k==1)
            {
                ans=root->val;
                k=-1;//no further update on answer is required
                return;
            }
            else --k;//we will search for next smaller element
            getAns(root->right,k,ans);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        getAns(root,k,ans);
        return ans;
    }
};
