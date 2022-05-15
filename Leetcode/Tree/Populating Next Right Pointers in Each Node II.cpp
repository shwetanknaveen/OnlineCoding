//Problem link - https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> qu;
        Node *thisNode;
        if(!root) return root;
        qu.push(root);
        while(!qu.empty())
            {
            int siz = qu.size();
            while(siz--)
                {
                thisNode = qu.front();
                qu.pop();
                if(siz!=0)//if this node is not the last node on this level
                   thisNode->next = qu.front();//set its next pointer to point to next node on the same level
                if(thisNode->left) qu.push(thisNode->left);
                if(thisNode->right) qu.push(thisNode->right);
                }
            }
       return root;
    }
};
