//Problem link - https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
//Video link - https://www.youtube.com/watch?v=sWf7k1x9XR4


//Approach 1 -> Recursive approach 	Time complexity = O(N) Space complexity = O(N)
class Solution {
public:
    TreeNode *prev;
    void flatten(TreeNode* root) {
        if(!root) return;	//Base condition
        
        //Hypothesis part
        flatten(root->right);//right subtree has to be visited first
        flatten(root->left);
        
        /*
        Imagine a tree link 	 1
        						/\
        					   /  \
        					  2   3
        It's flattening should result into 1->2->3
        Induction step at node 1 is executed when its both left and right subtrees are done.
        so when root->right = prev is done then prev should point to 2 hence left part execution should be done later
        than right part so that 2 is remembered as previous
        */
        
        //Induction part
        root->left = NULL;
        root->right = prev;
        prev = root;
    }
};

//Approach 2 -> Time complexity = O(N) Space complexity = O(1)

class Solution {
public:
    void flatten(TreeNode* root) {
      TreeNode *left,*right,*temp;
        
      while(root)
      {
        left = root->left;
        right = root->right;
        root->left = NULL;//As all left pointers have to point to NULL
        if(left)//if left part is not NULL then it has to be inserted as right between root and current right as root's right
        {
            root->right = left;//insert left as right of current root between root and current right
            temp = root;//now disconnected right has to connected in the end of newly connected left part
            while(temp->right)
                temp = temp->right;
            temp->right = right;
        }
        root = root->right;//one done with rearrangement at one node and setting its left to NULL, move to right
      }
    }
};


