//Problem link - https://practice.geeksforgeeks.org/problems/children-sum-parent/1/#

class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int childVal(Node *root)
    {
        if(!root) return 0;
        return root->data;
    }
    int isSumProperty(Node *root)
    {
     if(!root) return 1;//empty tree follows the property
     
     if(!root->left && !root->right) return 1;//left nodes don't violate the property as subtree
     
     if(childVal(root->left)+childVal(root->right) != root->data) return 0;//if this node doesn't follow property then return 0
     
     return isSumProperty(root->left)&&isSumProperty(root->right);//otherwise check for deeper nodes
     
    }
};

