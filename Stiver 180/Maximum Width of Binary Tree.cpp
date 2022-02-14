//Problem link - https://leetcode.com/problems/maximum-width-of-binary-tree/
//Video link - https://www.youtube.com/watch?v=ZbybYvcVLks

//Approach 1 ->Saving actual indices of each node
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int size;
        //Let's suppose all the nodes are stored in array like we did in heap sort in 1 based indexing
        unsigned long long int minIndex,maxIndex,maxi = 1;
        queue<pair<TreeNode*,unsigned long long int>> qu;//<Node,index>
        qu.push(make_pair(root,0));
        pair<TreeNode*,unsigned long long int> temp;
        while(!qu.empty())
        {
            size = qu.size();
            minIndex = qu.front().second;//min index at this level will be index of leftmost node at this level
            maxIndex = qu.back().second;//max index at this level will be index of rightmost node at this level
            while(size--)
            {
                temp = qu.front();
                qu.pop();
                if(temp.first->left) qu.push(make_pair(temp.first->left,2*temp.second));//index of left child is 2x(parent's index) {1 based indexing}
                if(temp.first->right) qu.push(make_pair(temp.first->right,2*temp.second+1));//index of right child is 2x(parent's index) + 1 {1 based indexing}
            }
            maxi = max(maxi,maxIndex-minIndex+1);//number of nodes between minIndex and maxIndex including both
        }
        return maxi;
        
    }
};

//Approach 2-> Saving indices of each node relatively by subtracting maxIndex so as to prevent the overflow

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int size;
        //Let's suppose all the nodes are stored in array like we did in heap sort in 1 based indexing
        int minIndex,maxIndex,maxi = 1;
        queue<pair<TreeNode*,int>> qu;//<Node,index>
        qu.push(make_pair(root,0));
        pair<TreeNode*,int> temp;
        while(!qu.empty())
        {
            size = qu.size();
            minIndex = qu.front().second;//min index at this level will be index of leftmost node at this level
            maxIndex = qu.back().second;//max index at this level will be index of rightmost node at this level
            while(size--)
            {
                temp = qu.front();
                qu.pop();
                if(temp.first->left) qu.push(make_pair(temp.first->left,2*(temp.second-maxIndex)));//index of left child is 2x(parent's index) {1 based indexing}
                if(temp.first->right) qu.push(make_pair(temp.first->right,2*(temp.second-maxIndex)+1));//index of right child is 2x(parent's index) + 1 {1 based indexing}
            }
            maxi = max(maxi,maxIndex-minIndex+1);//number of nodes between minIndex and maxIndex including both
        }
        return maxi;
        
    }
};
