//Problem link - https://leetcode.com/problems/recover-binary-search-tree/


//Approach 1 -
/*
Simply store the inorder in a vector, ideally for BST it should be sorted but here it won't be because of that swap.
We find one node from left whose value is bigger than its next node and one node from right whose value is smaller than next node(from R to L)
We swap their values
*/
class Solution {
public:
    void inorder(TreeNode *root,vector<TreeNode*> &in)
    {
        if(root)
        {
            inorder(root->left,in);
            in.push_back(root);
            inorder(root->right,in);
        }
    }
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> in;
        inorder(root,in);
        TreeNode *t1,*t2;
        for(int i=0;i<in.size()-1;i++)
        {
            if(in[i]->val>in[i+1]->val)
            {
                t1 = in[i];
                break;
            }
        }
        for(int i=in.size()-1;i>=1;i--)
        {
            if(in[i]->val<in[i-1]->val)
            {
                t2 = in[i];
                break;
            }
        }
        swap(t1->val,t2->val);
    }
};

//Approach 2 -> Same approach using single inorder traversal to get t1 and t2

class Solution {
public:
    
    TreeNode *t1,*t2,*prev;
    Solution()
    {
        t1=t2=prev=NULL;
    }
    void inorder(TreeNode *root)
    {
        if(!root)
            return;
        
        inorder(root->left);
        if(prev)//we have seen seen atleast one node in our traversal hence we can compare values of previously seen node and current node's value
        {
            if(prev->val>root->val)//ideally it should be ascending order, but here it implicates that this is swapped node
            {
                if(!t1)//if first node hasn't been found yet then t1 is set and it is first node from left in inorder hence t1 is set as prev
                    t1=prev;
                if(t1) //if first node has been set then t2 is set and it is first node from right in inorder hence t2 is set as root
                    t2=root;
            }

        }
        prev = root;//now prev is current node that is root
        inorder(root->right);
        
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(t1->val, t2->val);
    }
};
