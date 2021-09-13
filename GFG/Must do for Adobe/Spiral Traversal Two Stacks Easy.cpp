//Question link -https://practice.geeksforgeeks.org/problems/level-order-traversal-in-spiral-form/1
//Function to return a list containing the level order traversal in spiral form.
vector<int> findSpiral(Node *root)
{
    //Your code here
    vector<int> ans;
    if(!root) return ans;
    bool flip = false;
    stack<Node*> s1;
    stack<Node*> s2;
    s1.push(root);// Initially root is pushed onto the stack s1
    Node* curr;
    while((!s1.empty())||(!s2.empty()))
    {
        int n;
        if(flip) 
        n=s2.size();
        else
        n=s1.size();//initially flip is false and root is onto stack s1
         
        for(int i=0;i<n;i++)
        {
            if(!flip)//flip=false,take from s1 and push its children on s2 in RL order
            {
                curr = s1.top();
                s1.pop();
                if(curr->right!=NULL) s2.push(curr->right);
                if(curr->left!=NULL) s2.push(curr->left);
            }
            else//flip=true -> take from s2 and push its children on s1 in LR order
            {
                curr = s2.top();
                s2.pop();
                if(curr->left!=NULL) s1.push(curr->left);
                if(curr->right!=NULL) s1.push(curr->right);
            }
            ans.push_back(curr->data);
        }
        flip = !flip;//next time, this push and pop order has to be reversed
    }
    return ans;
}
