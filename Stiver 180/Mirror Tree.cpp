//Problem link - https://practice.geeksforgeeks.org/problems/mirror-tree/1#

class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void swapChild(Node *node)
    {
        Node *tempLeft = node->left;
        node->left = node->right;
        node->right = tempLeft;
    }
    void mirror(Node* node) {
        if(!node) return;	//Base condition
        
        //Hypothesis condition
        mirror(node->left);
        mirror(node->right);
        
        //Induction step
        swapChild(node);
    }
};
