//Problem link - https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
//Video link - https://www.youtube.com/watch?v=q_a6lpbKJdw


//Approach is simply to do level order traversal and save line,row and value as a tuple of each node in vector<tuples>
//Now sort this vector giving first priority to line then row then value as it is given that if line and row for many
//nodes are same then they have to be sorted
class Solution {
public:
    static bool comparator(tuple<int,int,int> t1,tuple<int,int,int> t2)//line,row,value
    {
        int l1=get<0>(t1),l2=get<0>(t2),r1=get<1>(t1),r2=get<1>(t2),val1=get<2>(t1),val2=get<2>(t2);
        if(l1<l2) return true;//give top priority to line in line order traversal
        else if(l1==l2)//if lines are same
        {
            if(r1<r2) return true;//then row should be given first priority
            else if(r1==r2) return val1<val2;//it is given that if line and row are same then values has to be sorted in ascending order
            else return false;//r1>r2
        }
        else return false;//l1>l2
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        vector<tuple<int,int,int>> vect;//   <line->row->nodeVal>
        queue<pair<TreeNode*,int>> qu;  //  <Node->line>
        qu.push(make_pair(root,0));
        pair<TreeNode*,int> temp;
        int row = 0;
        while(!qu.empty())//level order traversal
        {
            int size = qu.size();
            while(size--)
            {
            temp = qu.front();
            qu.pop();
            vect.push_back(make_tuple(temp.second,row,temp.first->val));
            if(temp.first->left)
                qu.push(make_pair(temp.first->left,temp.second-1));
            if(temp.first->right)
                qu.push(make_pair(temp.first->right,temp.second+1));
            }
            row++;
        }
        sort(vect.begin(),vect.end(),comparator);
        
        
        //Since each line has to be added in ans as seperate vector so we will keep trach of that
        int currLine = get<0>(vect[0]);//line number of first tuple
        vector<int> thisLineVals;
        for(auto p:vect)//p is a tuple <line,row,value>
        {
            if(get<0>(p)==currLine)//keep on pushing the node value in thisLineVals if it's in current line
            {
                thisLineVals.push_back(get<2>(p));
            }
            else
            {
                currLine = get<0>(p);
                ans.push_back(thisLineVals);
                thisLineVals.clear();
                thisLineVals.push_back(get<2>(p));//currLine changed and thisLineVals got cleared hence this tuple value
                								//shouldn't be skipped
            }
        }
        if(!thisLineVals.empty())//if currLine didn't change and thisLineVals left to be pushed in ans
        {
            ans.push_back(thisLineVals);
        }
        return ans;
        
    }
};
