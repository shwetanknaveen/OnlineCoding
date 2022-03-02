//Problem link - https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
//Video link - https://www.youtube.com/watch?v=ssL3sHwPeb4

//Same way we solved 2 sum here we are just doing that in preorder traversal
class Solution {
public:
    void getAns(TreeNode *root,int &k,unordered_set<int> &setNums,bool &ans)
    {
        if(root)
        {
            if(setNums.find(k-root->val) != setNums.end())
            {
                ans = true;
            }
            else
            {
                setNums.insert(root->val);
                getAns(root->left,k,setNums,ans);
                getAns(root->right,k,setNums,ans);
            }
        }
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> setNums;
        bool ans = false;
        getAns(root,k,setNums,ans);
        return ans;
    }
};
