//Problem link - https://www.interviewbit.com/problems/nearest-smaller-element/

//Question similar to next greater element

vector<int> Solution::prevSmaller(vector<int> &A) {
    stack<int> stc;
    vector<int> ans;
    for(int i:A)
    {
        while(!stc.empty() && stc.top()>=i)
            stc.pop();
        if(stc.empty())
            ans.push_back(-1);
        else ans.push_back(stc.top());

        stc.push(i);
    }
    return ans;
}

