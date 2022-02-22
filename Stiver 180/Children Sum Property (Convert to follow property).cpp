//Problem link - https://www.codingninjas.com/codestudio/problems/childrensumproperty_790723?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
//Video link - https://www.youtube.com/watch?v=fnmisPM6cVo&feature=youtu.be

//Check "Striver180/Children Sum Parent" https://practice.geeksforgeeks.org/problems/children-sum-parent/1/#
//Time complexity = O(N)
int childVal(BinaryTreeNode < int > * root)
    {
        if(!root) return 0;
        return root->data;
    }
void changeTree(BinaryTreeNode < int > * root) {
    if(root)
    {
        int childSum = childVal(root->left)+childVal(root->right);
        if(childSum<root->data)//preorder action
        {
        	//if child sum is less then we increase existing child to the value of root's data
            if(root->left) root->left->data = root->data;
            if(root->right) root->right->data = root->data;
        }
        else 
        {
            root->data = childSum;
        }
        changeTree(root->left);
        changeTree(root->right);
        if(root->left or root->right)//update shouldn't be for leaf nodes
        root->data = childVal(root->left)+childVal(root->right);//postorder action. Visiting node for last time hence
        														//update its value to sum of its children
    }
}  
