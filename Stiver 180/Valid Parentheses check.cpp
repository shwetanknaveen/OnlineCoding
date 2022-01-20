//Problem link - https://leetcode.com/problems/valid-parentheses/
//Video link - https://www.youtube.com/watch?v=wkDfsKijrZ8&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=75
class Solution {
public:
    bool isValid(string s) {
        stack<char> stc;
        for(char c:s)
        {
            if(c=='(' || c=='{' || c=='[')
                stc.push(c);
            
            else if(c==')')
            {
                if(stc.empty()) return false;
                if(stc.top()=='(')
                {
                    stc.pop();
                    continue;
                }
                else return false;
            }
            else if(c=='}')
            {
                if(stc.empty()) return false;
                if(stc.top()=='{')
                {
                    stc.pop();
                    continue;
                }
                else return false;
            }
            else if(c==']')
            {
                if(stc.empty()) return false;
                if(stc.top()=='[')
                {
                    stc.pop();
                    continue;
                }
                else return false;
            }
        }
        return (stc.empty());//it should be empty at the end
    }
};
