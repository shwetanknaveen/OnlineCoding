//See question "Diameter of a Binary Tree" GFG/DP -> https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1#
//Problem link -> https://leetcode.com/problems/diameter-of-binary-tree/
//Video link -> https://www.youtube.com/watch?v=zmPj_Ee3B8c&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=47


//Step -1 Base condition 
//Step -2 Hypothesis
//Step -3 Temporary answer and then using temporary store in answer in res variable
//Step -4 Return temp answer


//No need to implement DP here as each node is visited only once
class Solution {
  public:
    int solve(Node *root,int &res,map<Node*,int> &dp)
    {
        if(!root) return 0;//if no root then no node in the chain of diameter
        
        if(dp.find(root) != dp.end()) return dp[root];
        int l = solve(root->left,res,dp);//number of nodes for left part
        int r = solve(root->right,res,dp);//number of nodes for right part
        
        int temp = 1+max(l,r);//here root is not assumed the turning node i.e., the top node of diameter hence it propogates
        					//the maximum length including iteself upawards
        res = max(res,1+l+r);//result stores the best value among the previous value and if this root is taken as top
        					//node of diameter
        
        return dp[root] = temp;
    }
    int diameter(Node* root) {
        int res = INT_MIN;
        map<Node*,int> dp;
        solve(root,res,dp);//solve won't return the answer but in solve funtion we will store the answer
        return res-1;//we return res for https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1# as there max 
        			//no. of nodes between two leaf nodes is taken as diameter
    }
};

//As there is no need to implement DP here as each node is visited only once hence a more neat code below
class Solution {
public:
    int recHelper(TreeNode *root,int &res)
    {
        if(!root)
            return 0;
        int lh = recHelper(root->left,res);
        int rh = recHelper(root->right,res);
        
        res = max(res,lh+rh);
        return max(1+lh,1+rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        recHelper(root,res);
        return res;
    }
};

