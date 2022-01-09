//Problem link - https://practice.geeksforgeeks.org/problems/maximum-path-sum/1/#
//Video link - https://www.youtube.com/watch?v=ArNyupe-XH0&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=49


//Problem similar to Binary Tree Maximum Path sum in which we have to find max path sum between any two nodes and they need
//not be leaf nodes
class Solution {
public:
    int solve(Node *root,int &res,map<Node*,int> &dp)
    {
        if(!root) return 0;//if no root then no value of node in the chain of max sum
        if(!root->left && !root->right) return root->data;//for leaf node
        if(dp.find(root) != dp.end()) return dp[root];
        int l = solve(root->left,res,dp);//max sum of nodes for left part
        int r = solve(root->right,res,dp);//max sum of nodes for right part
        
        int maxOfLR = max(l,r);
        //we can't do the following here as here our end nodes of the max sum path should be leaf nodes only
        //if(maxOfLR<0) maxOfLR = 0;//if best of both part don't give a positive value then leave those parts as here we have
        						//option that we may start from any node and end at any node. Ending nodes of the path need
        						//not be leaf node
        						
        int temp;
        if(root->left && root->right)
        {
        temp = root->data+maxOfLR;//here root is not assumed the turning node i.e., the top node of max sum path hence it propogates
                                //the maximum sum including iteself upawards
                                
        res = max(res,root->data+l+r);//result stores the best value among the previous value and if this root is taken as top
        							//node of max sum path
        							//We can update the res only when both the child of root is existing otherwise form one side
        							//solve will return zero and from other side it may return some negative value and it will
        							//choose max as zero on the side where actually no node exists actually.
        }					
        else if(root->left)//only left child exist then save the temp depending only on left part as it may be negative
        					//and other part which is not existing will return 0 but we can't select that as it won't give
        					//leaf node
        temp = root->data + l;
        
        else//only right child exist then save the temp depending only on right part as it may be negative
        	//and other part which is not existing will return 0 but we can't select that as it won't give
        	//leaf node
        temp = root->data + r;
        
        
        return dp[root] = temp;
    }
    int maxPathSum(Node* root)
    {
        int res = INT_MIN;
        map<Node*,int> dp;
        int val = solve(root,res,dp);//solve won't return the answer but in solve funtion we will store the answer
        if(res!=INT_MIN)
        return res;
        else return val;//it is possible that our res never get updated and this happen when no where a node has two child
        				//in that case answer returned by solve() itself is the answer
    }
};
