//Problem link - https://leetcode.com/problems/range-sum-query-mutable/
//Video link - https://www.youtube.com/watch?v=dUkRI0R3sg8&t=1s
struct Node
{
    int sumOfChild,leftLim,rightLim;
    Node *leftChild,*rightChild;
    Node(int leftLim,int rightLim)
    {
        this->leftLim = leftLim;
        this->rightLim = rightLim;
        leftChild = NULL;
        rightChild = NULL;
        sumOfChild = 0;
    }
};

class NumArray {
public:
    Node *mainRoot;
    NumArray(vector<int> &nums) 
    {
        mainRoot = buildTree(nums,0,nums.size()-1);
    }
    
    void update(int index, int val) 
    {
        updateHelper(mainRoot,index,val);
    }
    
    int sumRange(int left, int right) 
    {
        return sumRangeHelper(mainRoot,left,right);
    }
    Node* buildTree(vector<int> &nums,int leftLim,int rightLim)
    {
        if(leftLim>rightLim) return NULL;
        if(leftLim==rightLim)//leaf node and leaf nodes have sumOfChild as node value itself
        {
            Node *leafNode = new Node(leftLim,rightLim);
            leafNode->sumOfChild = nums[leftLim];
            return leafNode;
        }
        
        Node *thisNode = new Node(leftLim,rightLim);
        int midLim = leftLim + (rightLim-leftLim)/2;
        Node *leftTree = buildTree(nums,leftLim,midLim);
        Node *rightTree = buildTree(nums,midLim+1,rightLim);
        thisNode->leftChild = leftTree, thisNode->rightChild = rightTree;
        thisNode->sumOfChild = leftTree->sumOfChild + rightTree->sumOfChild;
        return thisNode;
    }
    void updateHelper(Node *root,int &ind,int &newVal)
    {
        // cout<<"\nRoot sum value = "<<root->sumOfChild;
        if(root->leftLim==root->rightLim)//we have reached leaf node which has nums[index] value
        {
            root->sumOfChild = newVal;
        }
        else
        {
            int mid = root->leftLim + (root->rightLim-root->leftLim)/2;
            if(ind<=mid)
                updateHelper(root->leftChild,ind,newVal);
            else
                updateHelper(root->rightChild,ind,newVal);
            
            root->sumOfChild = root->leftChild->sumOfChild + root->rightChild->sumOfChild;//update childsum on backtrack
        }
    }
    int sumRangeHelper(Node *root,int leftLim,int rightLim)
    {
        if(root->leftLim==leftLim && root->rightLim==rightLim)
            return root->sumOfChild;
        
        int midLimOfRoot = root->leftLim + (root->rightLim - root->leftLim)/2;
        if(rightLim<=midLimOfRoot)
            return sumRangeHelper(root->leftChild,leftLim,rightLim);
        else if(leftLim>=midLimOfRoot+1)
            return sumRangeHelper(root->rightChild,leftLim,rightLim);
        else return (sumRangeHelper(root->leftChild,leftLim,midLimOfRoot) + sumRangeHelper(root->rightChild,midLimOfRoot+1,rightLim));
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
