//Question link - https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1
/*struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

// Should return  right view of tree
class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       // Your Code here
       vector<int> ans;
       if(!root)
       return ans;
       queue<Node*> q;
       q.push(root);
       Node *curr;
       while(!q.empty())
       {
           int n=q.size();
           for(int i=0;i<n;i++)
           {
               curr = q.front();
               q.pop();
               if(i==(n-1))
               {
                   ans.push_back(curr->data);//push the last node at each level into the ans vector
               }
               if(curr->left) q.push(curr->left);
               if(curr->right) q.push(curr->right);
           }
       }
       return ans;
    }
};

