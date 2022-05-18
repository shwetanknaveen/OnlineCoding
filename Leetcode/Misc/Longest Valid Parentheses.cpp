//Problem link - https://leetcode.com/problems/longest-valid-parentheses/

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stac;//this stack will keep indices of the parenthesis in the string s
        stac.push(-1);//We keep -1 initially so that if say s = () then when we encounter ) at index = 1 we pop one value from stack and see
        			//-1 on top of stack and put ans as max(0,1-(-1)) = 2
        int ans = 0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(') stac.push(i);
            else	//	')' is encountered
            {
                stac.pop();
                if(!stac.empty())//if stack is not empty after popping the top value then it means that there we valid number of open ( were
                				//seen so that this ) can be accomodated
                {
                    ans = max(ans,i-stac.top());
                }
                else
                {
                    stac.push(i);//if stack becomes empty then push this index so that this will act as index after which valid parenthesis
                    			//substring starts. It can be understood better with example
                }
            }
        }
        return ans;
    }
};
