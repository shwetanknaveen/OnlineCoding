//Problem link - https://practice.geeksforgeeks.org/problems/largest-bst/1/#
//See problem "Maximum sum BST in Binary Tree" in striver180


//Time complexity O(n) -> Post order traversal->We can judge about being BST or not at this node only after
//										we see both left subtree and right subtree of this node
class CustNode{
    public:
    int minVal,maxVal,maxBSTsize;
    CustNode(int minVal,int maxVal,int maxBSTsize)
    {
        this->minVal = minVal;
        this->maxVal = maxVal;
        this->maxBSTsize = maxBSTsize;
    }
};
class Solution{
    public:
    // Return the size of the largest sub-tree which is also a BST
    CustNode recHelper(Node *root,int &ans)
    {
    	//An empty tree is a BST of size 0
        if(!root)
            return CustNode(INT_MAX,INT_MIN,0);
            /*so that while comparison it doesn't affect others check for BST
            Largest on left should be smaller than node's value hence we pass largest as INT_MIN.
            Smallest on right should be larger than node's value hence we pass smallest as INT_MAX*/
        
        auto left = recHelper(root->left,ans);
        auto right = recHelper(root->right,ans);
        
        // Current node is greater than max in left AND smaller than min in right then it is a BST.
        if(root->data > left.maxVal && root->data < right.minVal)//It's a BST
        {
            int maxBSTsize = left.maxBSTsize + right.maxBSTsize + 1;
            ans = max(ans,maxBSTsize);//ans has to be maximum of all possibilites
            return CustNode(min(root->data,left.minVal),max(root->data,right.maxVal),maxBSTsize);
        }
        
        return CustNode(INT_MIN,INT_MAX,max(left.maxBSTsize,right.maxBSTsize));//else case when it's not a BST
        
        /*We pass minNode as INT_MIN and maxNode as INT_MAX so that it fails test for BST at other nodes which are 
        ancestor of this node.
        For BST,Largest on left should be smaller than node's value hence we pass largest as INT_MAX so that it is not
		smaller than anyone.
		For BST,Smallest on right should be larger than node's value hence we pass smallest as INT_MIN so that it is not
		larger than anyone.*/
    }
    int largestBst(Node *root)
    {
    	int ans = 0;
    	recHelper(root,ans);
    	return ans;
    }
};

