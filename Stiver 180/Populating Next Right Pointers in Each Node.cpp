//Problem link - https://leetcode.com/problems/populating-next-right-pointers-in-each-node/


class Solution {
public:
    Node* connect(Node* root) {
        Node *rootHolder = root,*level;
        while(root)//root will alway point to first node at each level
        {
            level = root;//level traversal will start from first node at each level
            while(level)
            {
                if(level->left)
                	level->left->next = level->right;//if this node's left exist then it's next should point to this node's right 
                if(level->right)//if this node's right child exist
                {
                    if(level->next)//and next node in this level exist
                        level->right->next = level->next->left;//then this node's right child's next should point to left
                        										//child of next node at this level
                }
                level = level->next;//move level node to next node at this level
            }
            root = root->left;
        }
        return rootHolder;
        
    }
};
