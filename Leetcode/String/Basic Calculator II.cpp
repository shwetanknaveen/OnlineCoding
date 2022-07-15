//Problem link - https://leetcode.com/problems/basic-calculator-ii/

class Solution {
public:
    int getNum(string &s,int &ind)//It will give a number (operand) and make the pointer point to next character after that number
    {
        int ans = 0;
        while(ind<s.length() && isdigit(s[ind]))
        {
            ans = 10*ans + (s[ind]-'0');
            ind++;
        }
        return ans;
    }
    
    /*
    All - and + operands are pushed on stack with their sign and *,/ are evaluated when encountered
    */
    int calculate(string s) 
    {
        int len = s.length(),op;
        stack<int> stack;
        
        for(int i=0;i<len;)
        {
            while(i<len && s[i]==' ') i++;//Skip spaces
            if(s[i]=='-')
            {
                i++;//go to next character
                while(i<len && s[i]==' ') i++;//skip space if any
                op = getNum(s,i);//get the operand and it will also advance the pointer
                stack.push(-op);//since sign was negative and push -op on the stack
            }
            else if(s[i]=='+')
            {
                i++;//go to next character
                while(i<len && s[i]==' ') i++;//skip space if any
                op = getNum(s,i);//get the operand and it will also advance the pointer
                stack.push(op);//push op as it is because sign was +
            }
            else if(s[i]=='*')//it has to be evaluated here only
            {
                int firstOp = stack.top();//first operand for multiplication must be on stack's top
                stack.pop();
                i++;//go to next character
                while(i<len && s[i]==' ') i++;//skip space if any
                op = getNum(s,i);//get second operand and it will advance the pointer also
                stack.push(firstOp * op);//push the multiplication result on the stack
            }
            else if(s[i]=='/')//it has to be evaluated here only
            {
                int firstOp = stack.top();//first operand for division must be on stack's top
                stack.pop();
                i++;//go to next character
                while(i<len && s[i]==' ') i++;//skip spaces if any
                op = getNum(s,i);//get second operand and it will advance the pointer also
                stack.push(firstOp / op);//push the division result on the stack
            }
            else//it's a number(operand)
            {
                op = getNum(s,i);
                stack.push(op);
            }
        }
        //Now evaluate the operands on the stack. We should note that op1-op2 is op1+(-op2) and
        //that's why we pushed negative operands with sign
        int ans = 0;
        while(!stack.empty())
        {
            ans += stack.top();
            stack.pop();
        }
        return ans;
    }
};
