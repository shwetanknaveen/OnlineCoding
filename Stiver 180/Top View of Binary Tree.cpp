//Problem link - https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1#
//Video link - https://www.youtube.com/watch?v=Et9OCDNvJ78&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=24

//We can't use recursive traversal as which value should or shouldn't overwrite will be decided by height and hence that
//will have to be taken into account apart from line number

class Solution
{
    public:
    vector<int> topView(Node *root)
    {
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
                
                mp.insert(make_pair(temp.second,temp.first->data));
                // mp[temp.second] = temp.first->data;//as we did in bottom view
                //https://stackoverflow.com/questions/17172080/insert-vs-emplace-vs-operator-in-c-map
                //Use insert() if we wish not to overwrite previous value.
                
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
