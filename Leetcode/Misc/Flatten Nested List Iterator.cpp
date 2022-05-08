//Problem link - https://leetcode.com/problems/flatten-nested-list-iterator/

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    vector<int> ans;
    int ind = 0;
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(auto ni : nestedList)
        {
            if(ni.isInteger())//This item is an integer
            {
                ans.push_back(ni.getInteger());//so simply push this integer in ans
            }
            else//this nestedInteger contains either list of integers or list of lists
            {
                auto lis = ni.getList();//get this list or list of lists
                NestedIterator obj(lis);
                while(obj.hasNext())//recursively we find that if this item has next then we get that item and put it in ans here
                {
                    ans.push_back(obj.next());
                }
            }
        }
    }
    
    int next() {
        return ans[ind++];
    }
    
    bool hasNext() {
        if(ind>=ans.size()) return false;
        return true;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
