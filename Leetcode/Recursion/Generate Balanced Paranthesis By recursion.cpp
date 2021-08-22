//Problem Link-https://leetcode.com/problems/generate-parentheses/submissions/
//Aditya verma link -  https://www.youtube.com/watch?v=eyCj_u3PoJE&list=PL_z_8CaSLPWeT1ffjiImo0sYTcnLzo-wY&index=17
class Solution {
public:
    void generator(int open,int close,string output,vector<string> &list){
        if(open>close) return;//can't be balanced as ) has been used more than (
        if(open == 0 && close ==0)//if both are emptied under the rule that at no time open>close then output contains bala-
        						//-nced paranthesises
        {
            list.push_back(output);
            return;
        }
        else if(open == 0 && close != 0)//in this case only closing parenthesis remains to be pushed
        {
            while(close--)
            {
                output.push_back(')');
            }
            list.push_back(output);
            return;
        }
        else//when open = close or open < close
        {
            string output1 = output;
            string output2 = output;
            output1.push_back('(');
            output2.push_back(')');
            generator(open-1,close,output1,list);
            generator(open,close-1,output2,list);
            
        }
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string> list;
        generator(n,n,"",list);
        return list;
    }
};

