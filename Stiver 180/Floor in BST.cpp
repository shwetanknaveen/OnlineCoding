//Problem link - https://www.codingninjas.com/codestudio/problems/floor-from-bst_920457?source=youtube&campaign=Striver_Tree_Videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=Striver_Tree_Videos&leftPanelTab=0
//Video link - https://www.youtube.com/watch?v=xm_W1ub-K-w&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=44

int floorInBST(TreeNode<int> * root, int X)
{
    int ans = root->val;
    while(root)
    {
        if(root->val==X)//if this X itself exist in the BST then it will be floor itself
        {
            ans = X;
            break;
        }
        else if(root->val>X)//if this node value is larger then we go left to search for a value <=X
        {
            root = root->left;
        }
        else//if this node value is smaller then we save this value as floor but go on right to search for better value->which
        {					//is <=X and more closer to it
            ans = root->val;
            root = root->right;
        }
    }
    return ans;
}
