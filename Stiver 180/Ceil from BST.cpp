//Problem link - https://www.codingninjas.com/codestudio/problems/ceil-from-bst_920464?source=youtube&campaign=Striver_Tree_Videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=Striver_Tree_Videos&leftPanelTab=1

int findCeil(BinaryTreeNode<int> *node, int x){
    int ans = -1;
    while(node)
    {
        if(node->data==x)//if this x itself exist in the BST then it will be ceil itself
        {
            ans = x;
            break;
        }
        else if(node->data>x)//if this node value is larger then we save this value as ceil but we go on right to search for 
        {		//better value->which is >=x and more closer to it
            ans = node->data;
            node = node->left;
        }
        else//if this node value is smaller then we go right to search for a value >=x
        {			
            node = node->right;
        }
    }
    return ans;
}
