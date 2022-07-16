//Problem link - https://leetcode.com/problems/fizz-buzz/

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        for(int i = 1;i<=n;i++)
        {
            bool divByThree = !(i%3), divByFive = !(i%5);
            if(divByThree && divByFive)
                ans.push_back("FizzBuzz");
            else if(divByThree)
                ans.push_back("Fizz");
            else if(divByFive)
                ans.push_back("Buzz");
            else
                ans.push_back(to_string(i));
        }
        return ans;
    }
};
