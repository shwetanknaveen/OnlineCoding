//Problem link - https://leetcode.com/problems/average-of-levels-in-binary-tree/

//Approach 1 -> BFS 
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) 
    {
        vector<vector<int>> levNodes;
        queue<TreeNode*> qu;
        TreeNode *temp;
        vector<double> ans;
        if(!root) return ans;
        qu.push(root);
        while(!qu.empty())
        {
           vector<int> lev;
           int size = qu.size();
           while(size--)
           {
               temp = qu.front();
               qu.pop();
               if(temp->left) qu.push(temp->left);
               if(temp->right) qu.push(temp->right);
               lev.push_back(temp->val);
           }
           levNodes.push_back(lev);
        }
        for(auto lev:levNodes)
        {
           double sum = 0.0;
           for(auto node: lev)
               sum += node;
           ans.push_back(sum/lev.size());
        }
        return ans;
    }
};

//Approach 2 -> DFS 

class Solution {
public:
    void dfs(TreeNode *root,int lev,vector<pair<double,int>> &levSumsCount)
    {
        if(!root) return;
        if(lev>=levSumsCount.size()) levSumsCount.push_back({0.0,0});//Each level when visited for first time, levSumsCount has
        															//to accomodate sum of nodes at that level and count number
        															//of nodes at that level
        levSumsCount[lev].first += root->val;
        levSumsCount[lev].second++;
        dfs(root->left,lev+1,levSumsCount);
        dfs(root->right,lev+1,levSumsCount);
    }
    vector<double> averageOfLevels(TreeNode* root) 
    {
        vector<pair<double,int>> levSumsCount;//<Sum of all nodes at a level,count of nodes at that level>
        vector<double> ans;
        dfs(root,0,levSumsCount);
        for(auto p:levSumsCount)
            ans.push_back(p.first/p.second);
        return ans;
    }
};
