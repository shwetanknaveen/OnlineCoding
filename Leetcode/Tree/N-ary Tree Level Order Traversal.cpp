//Problem link - https://leetcode.com/problems/n-ary-tree-level-order-traversal/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<Node*> qu;
        Node *temp;
        qu.push(root);
        while(!qu.empty())
        {
            int size = qu.size();
            vector<int> thisLevel;
            while(size--)
            {
                temp = qu.front();
                qu.pop();
                thisLevel.push_back(temp->val);
                for(auto child:temp->children)
                {
                    qu.push(child);
                }
            }
            ans.push_back(thisLevel);
        }
        return ans;
    }
};
