//Problem link - https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

//Video link - https://www.youtube.com/watch?v=UmJT3j26t1I

//Approach 1 Brute force method O(n^2)
class Solution {
public:
    TreeNode* insert(TreeNode *root,int val)
    {
        if(!root)//if root not created then create a root
        {
            root = new TreeNode(val);
        }
        else//search for the place where val can be created
        {
            TreeNode *tempRoot = root;
            while(tempRoot)
            {
                if(val<tempRoot->val)
                {
                    if(tempRoot->left)//next left child is not empty hence we can traverse further to search for right position
                        tempRoot = tempRoot->left;
                    else 
                        break;
                }
                else 
                {
                    if(tempRoot->right)//next right child is not empty hence we can traverse further to search for right position
                        tempRoot = tempRoot->right;
                    else
                        break;
                }
            }
            //now insert val at right place
            if(val<tempRoot->val)
                    tempRoot->left = new TreeNode(val);
            else tempRoot->right = new TreeNode(val);
        }
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode *root = NULL;
        for(int i: preorder)
        {
            root = insert(root,i);
        }
        return root;
    }
};


//Approach 2 -> Get sorted order as inorder traversal and then use usual consturction of binary tree using inorder and preorder
class Solution {
public:
    TreeNode* helper(int preStart,int preEnd,int inStart,int inEnd,vector<int> &pre,vector<int> &in,map<int,int> &inHash)
    {
        if(preStart>preEnd || inStart>inEnd)
            return NULL;
        TreeNode *root = new TreeNode(pre[preStart]);
        int indRoot = inHash[root->val];
        int numsOnLeft = inHash[root->val]-inStart;
        root->left = helper(preStart+1,preStart+numsOnLeft,inStart,indRoot-1,pre,in,inHash);
        				//preorder of left part starts one head from where it started and ends after covering all elements on left part
        				//inOrder of left starts from where it started and ends one before the index of root
        
        root->right = helper(preStart+numsOnLeft+1,preEnd,indRoot+1,inEnd,pre,in,inHash);
        				//preorder of right part starts one head from where preorder of left part ended and ends where it was originally ending
        				//inOrder of right starts one head of root and ends where it was ending
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> inHash;
        int end = inorder.size();
        for(int i=0;i<end;i++)
        {
            inHash[inorder[i]] = i;
        }
        return helper(0,end-1,0,end-1,preorder,inorder,inHash);
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;
        sort(inorder.begin(),inorder.end());
        return buildTree(preorder,inorder);
    }
};


//Approach 3 Striver's approach
//Time complexity = O(n)
class Solution {
public:
    TreeNode *recHelper(vector<int> &preorder,int &i,int upBound)
    {
        if(i==preorder.size() || preorder[i]>upBound)//equal value cases need not be dealt as there won't be equal values
            return NULL;							//in the given preorder
        
		//Preorder is root->left->right. We will go in this order only to add up nodes given in preorder
		TreeNode *root = new TreeNode(preorder[i++]);//make newNode for this value
        root->left = recHelper(preorder,i,root->val);//try to add remaining nodes ahead on left part first with upper limit
        											// as this node's value
        root->right = recHelper(preorder,i,upBound);//after trying on left part try to add remaining nodes on right part
        											//without changing the upper bound
        
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int ind = 0;
        return recHelper(preorder,ind,INT_MAX);//initially upper Bound is INT_MAX which means that value in the node can be
        										//	<=INT_MAX
    }
};

