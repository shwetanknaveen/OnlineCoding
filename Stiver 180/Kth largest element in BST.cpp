//Problem link - https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1

class Solution
{
    public:
	//In normal inorder traversal (left->root->right) we get ascending order of nodes but if we change it to (right->root->
	//left) then we get descending order of nodes and then we can find kth largest number in the same way as we found
	//kth smallest element
    void getAns(Node *root,int &k,int &ans)
    {
        if(root)
        {
            getAns(root->right,k,ans);
            if(k==1)
            {
                ans = root->data;
                k=-1;//no further update on answer is required
                return;
            }
            else k--;//we will search for next larger element
            getAns(root->left,k,ans);
        }
    }
    int kthLargest(Node *root, int K)
    {
        int ans;
        getAns(root,K,ans);
        return ans;
    }
};
