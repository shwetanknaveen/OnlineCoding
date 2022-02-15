//Problem link - https://leetcode.com/problems/same-tree/
//Video link - https://www.youtube.com/watch?v=BhuvF_-PWS0&feature=youtu.be

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p || !q)//if either of them is NULL
            return p==q;//both should be NULL for them to be same tree
        if(p->val != q->val) return false;//if value is not same then not same tree
        else return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);//value of this node is same then match for 
        																		//corresponding left and right subtrees
    }
};
