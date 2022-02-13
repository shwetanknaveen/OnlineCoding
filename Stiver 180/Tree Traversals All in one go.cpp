//Problem link - https://www.codingninjas.com/codestudio/problems/981269?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0
//Video link - https://www.youtube.com/watch?v=ySp2epYvgTE

void recTrav(BinaryTreeNode<int> *root,vector<int> &inOrd,vector<int> &preOrd,vector<int> &postOrd)
{
   if(root)
   {
       preOrd.push_back(root->data);
       recTrav(root->left,inOrd,preOrd,postOrd);
       inOrd.push_back(root->data);
	   recTrav(root->right,inOrd,preOrd,postOrd);
       postOrd.push_back(root->data);
       
   }
}
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    vector<int> inOrd,preOrd,postOrd;
    vector<vector<int>> ans;
    recTrav(root,inOrd,preOrd,postOrd);
    ans.push_back(inOrd);
    ans.push_back(preOrd);
    ans.push_back(postOrd);
    return ans;
}
