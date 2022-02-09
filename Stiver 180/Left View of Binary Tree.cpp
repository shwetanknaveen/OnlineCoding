//Problem link - https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1#

//Approach 1- Time complexity = O(N)	Space complexity = O(N)=>At last stage store all the last level nodes which may be N/2
//Will do level order traversal from left to right at each level. Push the first value at each level in ans.

vector<int> leftView(Node *root)
{
   queue<Node*> qu;
   qu.push(root);
   Node *temp;
   int size;
   vector<int> ans;
   if(!root) return ans;
   while(!qu.empty())
   {
       size = qu.size();
       ans.push_back(qu.front()->data);
       while(size--)
       {
           temp = qu.front();
           if(temp->left)
            qu.push(temp->left);
           if(temp->right)
            qu.push(temp->right);
           
           qu.pop();
       }
   }
   return ans;
}

//Approach 2- Time complexity = O(N)	Space complexity = O(Height)
//Video link - https://www.youtube.com/watch?v=KV4mRzTjlAk&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=26
void recHelper(Node *root,int level,vector<int> &ans)
{
    if(!root) return;
    if(ans.size()==level) ans.push_back(root->data);
    recHelper(root->left,level+1,ans);//We first go root->right for Right view of binary tree
    recHelper(root->right,level+1,ans);
}
vector<int> leftView(Node *root)
{
   vector<int> ans;
   recHelper(root,0,ans);
   return ans;
}

