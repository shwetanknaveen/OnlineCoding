//Must do for Oracle
// Question link - https://practice.geeksforgeeks.org/problems/connect-nodes-at-same-level/1
void connect(Node *root)
    {
       // Your Code Here
       if(root==NULL)return;
       root->nextRight = NULL;//explicitly doing it for root node
       queue<Node*> q;
       q.push(root);
       
        Node* curr;
        //Behtareen BFS ka istemal by Mayank
       while(!q.empty()){
         
           int n=q.size();
         
             for(int i=0;i<n;i++){
                Node *pre =  curr;
                 curr = q.front();
                 q.pop();
                 
                 if(i!=0) pre->nextRight=curr;//first node at each level won't be
                                                //pointed by any node
                 if(i==n-1) curr->nextRight = NULL;//last node at each level would point to NULL
                 if(curr->left!=NULL)q.push(curr->left);
                 if(curr->right!=NULL)q.push(curr->right);
            }
       }
    }
    
    
    
    
    
