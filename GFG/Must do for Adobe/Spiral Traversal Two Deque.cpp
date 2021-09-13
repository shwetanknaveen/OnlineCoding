//Question link - https://practice.geeksforgeeks.org/problems/level-order-traversal-in-spiral-form/1
/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */


//Function to return a list containing the level order traversal in spiral form.
vector<int> findSpiral(Node *root)
{
    //Your code here
    vector<int> ans;
    if(!root) return ans;
    bool flip = false;
    deque<Node*> q1;
    deque<Node*> q2;
    q1.push_back(root);// Initially root is pushed onto the deq q1
    Node* curr;
    while((!q1.empty())||(!q2.empty()))
    {
        int n;
        if(flip) 
        n=q2.size();
        else
        n=q1.size();//initially flip is false and root is onto the deq q1
         
        for(int i=0;i<n;i++)
        {
            if(!flip)//flip=false,take from deq q1's back and push its children on deq q2's front in RL order
            {
                curr = q1.back();
                q1.pop_back();
                if(curr->right!=NULL) q2.push_front(curr->right);
                if(curr->left!=NULL) q2.push_front(curr->left);
            }
            else//flip=true -> take from deq q2's front and push its children on deq q1's front in LR order
            {
                curr = q2.front();
                q2.pop_front();
                if(curr->left!=NULL) q1.push_back(curr->left);
                if(curr->right!=NULL) q1.push_back(curr->right);
            }
            ans.push_back(curr->data);
        }
        flip = !flip;//next time, this push and pop order has to be reversed
    }
    return ans;
}
