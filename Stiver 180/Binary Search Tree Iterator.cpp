//Problem link - https://leetcode.com/problems/binary-search-tree-iterator/
//https://www.youtube.com/watch?v=D2jMcmxU4bs

//Approach 1 -> Brute force method
class BSTIterator {
public:
    int ind;
    vector<int> inord;
    void initInord(TreeNode *root)
    {
       if(root)
        {
            initInord(root->left);
            inord.push_back(root->val);
            initInord(root->right);
        } 
    }
    BSTIterator(TreeNode* root) {
        ind = -1;
        initInord(root);//put inorder traversal in inord vector
    }
    
    int next() {
        return inord[++ind];//as all next() calls are valid hence simply return values at next indices
    }
    
    bool hasNext() {
        return ind<(int(inord.size())-1);//size() returns unsigned long int which will cause issue here hence we cast it to
        								//int so that RHS of this boolean expression get evaluated as int
    }
};

//Approach 2 
//Idea is to push all the nodes on left having left child and then push that node on top which has
//no left child so that it gets returned in next(). We keep NULL on top of stack if all nodes are
//exhausted and we have no further next().
//When we take next() from top of stack then we know that its left part has been processed, so we
//process its right part
class BSTIterator {
public:
    stack<TreeNode*> stac;
    
    BSTIterator(TreeNode* root) //push the nodes on stack such that top of stack gets the smallest number
    {
        while(root && root->left)
        {
            stac.push(root);
            root = root->left;
        }
        stac.push(root);//now this root has no left child or this root is NULL. If this has no left child then it
                        //will be "next" to be returned in next()
        
    }
    
    int next() {
        int retVal = stac.top()->val;
        TreeNode *newRoot = NULL;
        if(stac.top())
            newRoot = stac.top()->right;
        stac.pop();
        
        while(newRoot && newRoot->left)
        {
            stac.push(newRoot);
            newRoot = newRoot->left;
        }
        if(newRoot || stac.empty())//Push NULL node on stack only if there are no nodes to process 
            stac.push(newRoot);         //further on stac
        return retVal;
    }
    
    bool hasNext() {
        if(stac.top()) return true;//if top of stack is not NULL node then we have next
        return false;
    }
};

//More neat code with above approach where we don't keep NULL on top of stack is we don't have next element rather our
//stack is empty in that case

class BSTIterator {
    stack<TreeNode *> myStack;
public:
    BSTIterator(TreeNode *root) {
        pushAll(root);//push all the elements on the left
    }

    bool hasNext() {
        return !myStack.empty();
    }

    int next() {//next() call is always valid hence no empty() check
        TreeNode *tmpNode = myStack.top();
        myStack.pop();//remove this next element
        pushAll(tmpNode->right);//this next element's left part including it has been processed hence now go to its right part
        						//In case if right part is NULL then it won't push anything
        return tmpNode->val;
    }

private:
    void pushAll(TreeNode *node) {
        for (; node != NULL; myStack.push(node), node = node->left);//no initialisation, one conditional check and two statements in 
        															//incremental part
    }
};
