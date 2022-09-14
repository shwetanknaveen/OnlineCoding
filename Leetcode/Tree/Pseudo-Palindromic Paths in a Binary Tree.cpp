//Problem link - https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/


class Solution {
public:
    int ans,total;
    bool isLeaf(TreeNode *root)
    {
        return ((!(root->left)) && (!(root->right)));
    }
    bool isPalin(vector<int> &valCount)
    {
        if(total&1)//odd number of elements
        {
            bool oneOdd = false;//one odd frequency is allowed in odd number length palindrome
            for(auto p:valCount)
            {
                if(p&1)
                {
                    if(!oneOdd) oneOdd = true;
                    else return false;
                }
                //do nothing in else
            }
        }
        else//even number of elements
        {
            for(auto p:valCount)//No odd frequency is allowed in even length palindrome
            {
                if(p&1)
                {
                    return false;
                }
                //do nothing in else
            }
        }
        return true;
    }
    void solve(TreeNode *root,vector<int> &valCount)
    {
        if(!root) return;
        valCount[root->val-1]++;
        total++;
        solve(root->left,valCount);
        solve(root->right,valCount);
        
        if(isLeaf(root))
        {
            if(isPalin(valCount)) ans++;
        }
        valCount[root->val-1]--;
        total--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        ans = total = 0;//total keeps track of total number of nodes in this path from root to leaf
        vector<int> valCount(9,0);//Numbers are from 1 to 9
        solve(root,valCount);
        return ans;
    }
};
