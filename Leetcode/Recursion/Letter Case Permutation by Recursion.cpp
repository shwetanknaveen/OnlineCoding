//Problem link - https://leetcode.com/problems/letter-case-permutation/
//Aditya verma video link - https://www.youtube.com/watch?v=4eOPYDOiwFo&list=PL_z_8CaSLPWeT1ffjiImo0sYTcnLzo-wY&index=16
class Solution {
public:
    void solve(string input, string output,vector<string> &list)
    {
        if(input.length()==0)
        {
            list.push_back(output);//if all decisions have been made on input then simply push current output to the list of
            						//all outputs
            return;
        }
        if(isalpha(input[0]))//if the next symbol in input is an alphabet on which the decision has to be made
        {
            string output1 = output;
            string output2 = output;
            output1.push_back(tolower(input[0]));//output-1 will choose the alphabet from input in lower case
            output2.push_back(toupper(input[0]));//output-2 will choose the alphabet from output in upper case
            input.erase(input.begin()+0);//erase the letter from input after making decisions on it
            solve(input,output1,list);
            solve(input,output2,list);
        }
        else//for the case when next letter in input is number
        {
            output.push_back(input[0]);//simply push the number
            input.erase(input.begin()+0);//erase the letter from input after making decisions on it
            solve(input,output,list);
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> list;
        solve(s,"",list);//initially our output is empty string
        return list;
    }
};
