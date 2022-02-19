//Problem link - https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
//Video link - https://www.youtube.com/watch?v=LgLRTaEMRVc&feature=youtu.be

//Approach 1- Modify post order by reversing it from left->right->root to root->right->left and then do tweakings in 
//the way we constructed Binary tree from preorder and inorder traversals

class Solution {
public:
	//here received preorder is modified which is root->right->left
    TreeNode* helper(int preStart,int preEnd,int inStart,int inEnd,vector<int> &pre,vector<int> &in,map<int,int> &inHash)
    {
        if(preStart>preEnd || inStart>inEnd)
            return NULL;
        TreeNode *root = new TreeNode(pre[preStart]);
        int indRoot = inHash[root->val];
        int numsOnRight = inEnd - inHash[root->val];
        root->right = helper(preStart+1,preStart+numsOnRight,indRoot+1,inEnd,pre,in,inHash);
        				//preorder of right part starts one head from where it started and ends after covering all elements on right part
        				//inOrder of right part starts from one ahead of index of root where it started and ends where it was ending before
        
        root->left = helper(preStart+numsOnRight+1,preEnd,inStart,indRoot-1,pre,in,inHash);
        				//preorder of left part starts one head from where preorder of right part ended and ends where it was originally ending
        				//inOrder of left starts from where it was starting originally and ends before index of root.
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        reverse(postorder.begin(),postorder.end());//root->right->left
        map<int,int> inHash;
        int end = inorder.size();
        for(int i=0;i<end;i++)
        {
            inHash[inorder[i]] = i;
        }
        return helper(0,end-1,0,end-1,postorder,inorder,inHash);//postorder passed as modified preorder
    }
};

//Approach 2 -> Usual apporach with which we constructed Binary tree from preorder and inorder traversals

class Solution {
public:
    TreeNode *helper(vector<int> &post,int postStart,int postEnd,vector<int> &in,int inStart,int inEnd,map<int,int> &inHash)
    {
        if(postStart>postEnd || inStart>inEnd)
            return NULL;
         
        TreeNode *root = new TreeNode(post[postEnd]);//root is at the end of post order
        int rootInd = inHash[root->val];
        int numsOnRight = inEnd - rootInd;
        
        root->right = helper(post,postEnd-numsOnRight,postEnd-1,in,rootInd+1,inEnd,inHash);
        root->left = helper(post,postStart,postEnd-numsOnRight-1,in,inStart,rootInd-1,inHash);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> inHash;
        int end = inorder.size();
        for(int i=0;i<end;i++)
            inHash[inorder[i]] = i;
        return helper(postorder,0,end-1,inorder,0,end-1,inHash);
    }
};
