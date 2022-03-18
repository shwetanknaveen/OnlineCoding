//Problem link - https://leetcode.com/problems/clone-graph/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        queue<Node*> nextToProcess;
        unordered_map<Node*,bool> visited;//Node has been added on queue to process its neighbors and it won't be added again
        unordered_map<Node*,Node*> oldNew;
        nextToProcess.push(node);
        visited[node] = true;
        while(!nextToProcess.empty())
        {
            Node *thisNode = nextToProcess.front();
            nextToProcess.pop();
            if(oldNew.find(thisNode)==oldNew.end())//new node for this node hasn't been created yet
            {
                oldNew[thisNode] = new Node(thisNode->val);
            }
            for(auto n:thisNode->neighbors)//start processing its neighbors
            {
                if(oldNew.find(n)==oldNew.end())//if clone of this neighbor doesn't exist
                {
                    oldNew[n] = new Node(n->val);//first create a clone
                    oldNew[thisNode]->neighbors.push_back(oldNew[n]);//map cloned neighbor to neighbor list of clone of this node
                }
                else//if clone of this neighbor already exist
                {
                    oldNew[thisNode]->neighbors.push_back(oldNew[n]);//map cloned neighbor to neighbor list of clone of this node
                }
                if(!visited[n])//if this neighbor hasn't been processed yet on queue then add it
                {
                    nextToProcess.push(n);
                    visited[n] = true;
                }
            }
        }
        return oldNew[node];//return cloned copy of original node
    }
};
