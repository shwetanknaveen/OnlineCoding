//Problem link - https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1/#
//Video link - https://www.youtube.com/watch?v=0ca1nvR0be4

class Solution {
public:
    bool isLeaf(Node *root)
    {
        return (!root->left && !root->right);
    }
    void preorder(Node *root,vector<int> &leafNodes)//Leaf nodes should come in order from left to right.It could have been
    												//have been disturebed(left to right order) if we use level order traversal
    												//for adding leaf nodes
    {
        if(root)
        {
            if(isLeaf(root))
                leafNodes.push_back(root->data);
            preorder(root->left,leafNodes);
            preorder(root->right,leafNodes);
        }
    }
    vector <int> boundary(Node *root)
    {
        vector<int> leftNodes,rightNodes,leafNodes;
        if(!isLeaf(root))//main root is separately added if it's not a leaf node
            leftNodes.push_back(root->data);
            
        Node *temp = root->left;//start from left subtree for left side nodes
        while(temp)
        {
            if(!isLeaf(temp))
                leftNodes.push_back(temp->data);
            if(temp->left) 
                temp=temp->left;
            else 
                temp = temp->right;
        }
        
		temp = root->right;//start from right subtree for right side nodes
        while(temp)
        {
            if(!isLeaf(temp))
                rightNodes.push_back(temp->data);
            if(temp->right) 
                temp=temp->right;
            else 
                temp = temp->left;
        }
        reverse(rightNodes.begin(),rightNodes.end());//In anticlockwise boundary traversal,right side nodes from top to 
        											//bottom will be reversed
        preorder(root,leafNodes);
        leftNodes.insert(leftNodes.end(),leafNodes.begin(),leafNodes.end());//append leaves in left nodes
        leftNodes.insert(leftNodes.end(),rightNodes.begin(),rightNodes.end());//append right nodes in merged list
        return leftNodes;
    }
};
