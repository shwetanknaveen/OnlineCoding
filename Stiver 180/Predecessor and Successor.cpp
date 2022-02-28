//Problem link - https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1#
//Video link - https://www.youtube.com/watch?v=SXKAD2svfmI&feature=youtu.be

//Approach 1 - Brute force method
//Time complexity = O(n) Space complexity = O(n)

int inord[100];
int lastInd;
void inorder(Node *root)
{
    if(root)
    {
        inorder(root->left);
        inord[++lastInd]=root->key;
        inorder(root->right);
    }
}
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    lastInd = -1;
    inorder(root);
    
    for(int i=0;i<=lastInd;i++)
    {
        if(inord[i]==key)//if key exists in the BST itself
        {
            if(i>0)//it's not the first node in inorder traversal then predecessor will exist for it
            pre = new Node(inord[i-1]);
            
            if(i<lastInd)//if it's not the last node in inorder traversal then successor will exist for it
            suc = new Node(inord[i+1]);
            
            
            break;//after initialisation, break the loop
        }
        if(i>0)//key doesn't exist in BST but it is between two consecutive values of inorder traversal which will act as 
        		//its predecessor and successor
        {
            if(key>inord[i-1] && key<inord[i])
            {
                pre = new Node(inord[i-1]);
                suc = new Node(inord[i]);
                break;
            }
        }
        if(i==0 && inord[i]>key)//key is smaller than the smallest element then only successor for key will exist which will
        						//will be the smallest number
        {
            suc = new Node(inord[i]);
            break;
        }
        if(i==lastInd && inord[i]<key)//key is larger than the largest element then only predecessor for key will exist which
        								//will be the largest number
        {
            pre = new Node(inord[i]);
            break;
        }
    }
}

//Approach 2 
//Time complexity = O(n) Space complexity - Only stack space


void inorder(Node *root,int &pre,int &succ,int &key)
{
    if(root)
    {
        inorder(root->left,pre,succ,key);
        if(root->key<key)//if this value is less than key value
        {
            if(key-root->key<key-pre)//if this value is nearer than previous value which was less than key then update
                pre = root->key;
        }
        if(root->key>key)
        {
            if(root->key-key<succ-key)//if this value is nearer than previous value which was greater than key then update
                succ = root->key;
        }
        inorder(root->right,pre,succ,key);
    }
}
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    int pred = -10000,succ = 10000;//-inf and +inf values
    inorder(root,pred,succ,key);
    if(pred != -10000)
        pre = new Node(pred);
    if(succ != 10000)
        suc = new Node(succ);

}







//Approach 3 -> If we try to find predecessor and successor individually then we can do that in O(height) 
//See "Inorder successor in BST" on leetcode soln in striver180 folder

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    int succ = -1,pred = -1;
    Node *tempRoot = root;
    while(tempRoot)//for successor
        {
            if(tempRoot->key>key)//answer will always be on right part so if we are going left then we might be missing ans
            {
                succ = tempRoot->key;//first store potential successor in succ
                tempRoot = tempRoot->left;
            }
            else
            {
                tempRoot = tempRoot->right;
            }
        }
    tempRoot = root;
    while(tempRoot)//for predeccessor
        {
            if(tempRoot->key>=key)
            {
                tempRoot = tempRoot->left;
            }
            else//answer will always be on left part so if we are going right then we might be missing ans
            {
                pred = tempRoot->key;//first store potential predecessor in succ
                tempRoot = tempRoot->right;
            }
        }
        
    if(succ != -1)
        suc = new Node(succ);
    if(pred != -1)
        pre = new Node(pred);
    
}
