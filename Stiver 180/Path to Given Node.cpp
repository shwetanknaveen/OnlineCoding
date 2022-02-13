//Problem link - https://www.interviewbit.com/problems/path-to-given-node/
//Video link - https://www.youtube.com/watch?v=fmflMqVOC7k

//CODE 1 - My first submitted code
bool recHelper(TreeNode *root,int &B,vector<int> &ans)
{
    if(!root)
    {
        return false;
    }
    ans.push_back(root->val);
    if(root->val==B) return true;//We reached the desired node
    else
    {
        int origSize = ans.size();
        bool l = recHelper(root->left,B,ans);
        if(!l)//couldn't find it on left
        {
            int sizeDiff = ans.size()-origSize;
            while(sizeDiff--) ans.pop_back();//pop all the elements which are added while gone on left part
            return recHelper(root->right,B,ans);//now search on right
        }
        else return true;//found on left path and path will be saved on ans
    }
}
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ans;
    recHelper(A,B,ans);
    return ans;
}

//CODE 2 - More neat code - Striver
bool getPath(TreeNode *root, vector<int> &arr, int x) {
    // if root is NULL,there is no path
    if (!root)
        return false;
     
    // push the node's value in 'arr'
    arr.push_back(root->val);   
     
    // We reached the desired node
    if (root->val == x)   
        return true;
     
    // else check whether the required node lies in the left subtree or right subtree of the current node
    if (getPath(root->left, arr, x) || getPath(root->right, arr, x))/* Suppose the first condition evaluates to false
    																   then it will pop all the nodes which were pushed
    																   on arr while going left and searching for x as they
    																   all will fall to else case (not explicitly written
																	   else case but after return of this block)
																	*/
        return true;
     
    // required node does not lie either in the left or right subtree of the current node.Thus, remove current node's value 
    // from 'arr'and then return false.
    arr.pop_back();
    return false;  
}
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> arr; 
    getPath(A, arr, B);//No need to check the return value as true/false as it is given that B will always exist
    return arr; 
}
