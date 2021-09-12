//Problem link - https://practice.geeksforgeeks.org/problems/check-for-bst/1#
class Solution
{
    public:
    //Function to check whether a Binary Tree is BST or not.
    bool utilityRec(Node *node,int max,int min)
    {
        if(!node) return true;//if node doesn't exist then obviously it won't violate BST condition
        
        if(node->data > max || node->data < min)//TRICK- Here we think first mainly from negative case point of view
        return false;                           //i.e., in what condition the BST condition will fail
        
        else return (utilityRec(node->left,node->data-1,min) && //if we are going left then max values that left node can assume is 1 less than current node's value
                    utilityRec(node->right,max,node->data+1));//if we are going right then min values that right node can assume is 1 more than current node's value
    }
    bool isBST(Node* root) 
    {
        // Your code here
        return utilityRec(root,INT_MAX,INT_MIN);//initially root can have any int value so we pass min as INT_MIN and max as INT_MAX
    }
};
