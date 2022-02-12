//Problem link - https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1#
//Video link - https://www.youtube.com/watch?v=0FtVY6I4pB8&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=24

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int> ans;
        if(!root) return ans;
        map<int,int> mp;//line->nodeData
        queue<pair<Node*,int>> qu;//node->line
        //int size;
        qu.push(make_pair(root,0));//root is on line number 0
        pair<Node*,int> temp;
        while(!qu.empty())
        {
            // size = qu.size();
            // while(size--)		WE DON'T NEED TO DO SOMETHING AT BEGINNING/ENDING AT EACH LEVEL, JUST WHOLE TREE IN 
            // {					LEVEL ORDER HAS TO BE TRAVERSED HENCE NO NEED FOR THIS INSIDE LOOP
                temp = qu.front();
                qu.pop();
                
                //mp.insert(make_pair(temp.second,temp.first->data));
                mp[temp.second] = temp.first->data;//node data is mapped to its line number =>	<lineNo. -> NodeData>
                //https://stackoverflow.com/questions/17172080/insert-vs-emplace-vs-operator-in-c-map
                //Don't use insert() if we wish to overwrite previous value rather use emplace [] operator as above
                
                if(temp.first->left)//if left of this node exist then its line number will be one less
                {
                    qu.push(make_pair(temp.first->left,temp.second-1));
                }
                if(temp.first->right)//if right of this node exist then its line number will be one more
                {
                    qu.push(make_pair(temp.first->right,temp.second+1));
                }
            // }
        }
        for(auto p:mp)//map will automatically be sorted on basis of line numbers
            ans.push_back(p.second);
        return ans;
    }
};
