//Problem link - https://practice.geeksforgeeks.org/problems/root-to-leaf-path-sum/1
class Solution
{
    public:
    bool hasPathSum(Node *root, int S) 
	{
    if(!root){ return S==0;}//if we have travelled towards end and sum is zero then return true otherwise return false
    return hasPathSum(root->right, S-root->data) || hasPathSum(root->left, S-root->data);
	}
};
