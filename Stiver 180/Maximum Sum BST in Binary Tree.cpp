//Problem link - https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/
//Video link - https://www.youtube.com/watch?v=X0oXMdtUDwo

//Approach 1 -> Brute force method-> Will give TLE
class Solution {
public:
    int sum(TreeNode *root)
    {
        if(!root) return 0;
        return root->val + sum(root->left) + sum(root->right);
    }
    void preorder(TreeNode *root,int &ans)
    {
        if(root)
        {
            if(isBST(root,LONG_MIN,LONG_MAX))
            {
                ans = max(ans,sum(root));
            }
            preorder(root->left,ans);
            preorder(root->right,ans);
        }
    }
    bool isBST(TreeNode *root,long min,long max)
    {
        if(!root) return true;
        if(root->val<min || root->val>max) return false;
        long curr = root->val;
        return isBST(root->left,min,curr-1) && isBST(root->right,curr+1,max);
    }
    int maxSumBST(TreeNode* root) {
        int ans = INT_MIN;
        preorder(root,ans);
        return ans>0?ans:0;
    }
};

//Approach 2-> Time complexity O(n) -> Post order traversal->We can judge about being BST or not at this node only after
//										we see both left subtree and right subtree of this node

class NodeValue {
public:
    int maxNode, minNode, BSTsum;
    
    NodeValue(int minNode, int maxNode, int BSTsum) {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->BSTsum = BSTsum;
    }
};
class Solution {
public:
    NodeValue largestBSTSubtreeHelper(TreeNode* root,int &ans) {
        // An empty tree is a BST of sum 0.
        if (!root) {
            return NodeValue(INT_MAX, INT_MIN, 0);//so that while comparison it doesn't affect others check for BST
            //Largest on left should be smaller than node's value hence we pass largest as INT_MIN.
            //Smallest on right should be larger than node's value hence we pass smallest as INT_MAX
        }
        
        // Get values from left and right subtree of current tree.
        auto left = largestBSTSubtreeHelper(root->left,ans);
        auto right = largestBSTSubtreeHelper(root->right,ans);
        
        // Current node is greater than max in left AND smaller than min in right then it is a BST.
        if (left.maxNode < root->val && root->val < right.minNode) {
            // It is a BST.
            int BSTsum = left.BSTsum + right.BSTsum + root->val;
            ans = max(ans,BSTsum);//ans has to be maximum of all possibilites
            return NodeValue(min(root->val, left.minNode), max(root->val, right.maxNode), 
                            BSTsum);
        }
        return NodeValue(INT_MIN, INT_MAX, max(left.BSTsum, right.BSTsum));//else case when it's not a BST
        
        //We pass minNode as INT_MIN and maxNode as INT_MAX so that it fails test for BST at other nodes which are 
        //ancestor of this node.
        //For BST,Largest on left should be smaller than node's value hence we pass largest as INT_MAX so that it is not
		//smaller than anyone.
		//For BST,Smallest on right should be larger than node's value hence we pass smallest as INT_MIN so that it is not
		//larger than anyone.
		
    }
    int maxSumBST(TreeNode* root) {
        int ans = 0; 
        largestBSTSubtreeHelper(root,ans);
        return ans;
    }
};
