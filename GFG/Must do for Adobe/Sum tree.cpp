//Problem link - https://practice.geeksforgeeks.org/problems/sum-tree/1#
class Solution
{
    public:
    unordered_map<Node *,int> sums;	//for using dynamic programing. sums[node] gives sum of children of node
    int getChildSum(Node *node)
    {
        if(!node) return 0;
        if(sums.find(node) != sums.end())
        return sums[node];	//if sum was previously calculated then return it- Dynamic programming
        int sum = 0;
        if(node->left)
        sum += node->left->data + getChildSum(node->left);//add left node and its children
        if(node->right)//don't use else if because we want to sum each child (left and right) individually if they exist
        sum += node->right->data + getChildSum(node->right);//add right node and its children
        
        sums[node] = sum;	//before returning value, save the calculated sum - Dynamic programming
        return sum;
    }
    bool isSumTree(Node* root)
    {
         if(!root) return true;
         else if(!root->left && !root->right)//leaf node doesn't violate the condition
         return true;
         else if(root->data == getChildSum(root))//if this node pass the condtion then we check for its children
         {
            return (isSumTree(root->left) && isSumTree(root->right));
         }
         else return false;//default case is returning false
         
    }
};

