//Problem link - https://leetcode.com/problems/remove-k-digits/
//Time and space complexity -> O(n)
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> nums;
        int popped = 0;
        int n=num.length();
        for(int i=0;i<n;i++)
        {
            if(popped!=k && !nums.empty() && nums.top()>num[i])/*if we haven't popped required no. of elements and stack is
			not empty and top of stack that is what we have seen earlier at left side is bigger than what's coming next then
			we need to pop the bigger digit to make number smaller*/
            {
                    nums.pop();
                    popped++;
                    i=i-1;//restore i so that same digit can be rechecked with top of stack
                    continue;
            }
            else
            {
                if(nums.empty())
                {
                    if(num[i]!='0')//putting 0 at first place in final answer won't make sense
                    nums.push(num[i]);
                }
                else
                    nums.push(num[i]);
            }
        }
        while(popped<k)//forced to delete from back
        {
            if(!nums.empty())
            nums.pop();
            popped++;
        }
        string ans;
        while(!nums.empty())
        {
            ans = nums.top() + ans;//significant digits are at top of stack
            nums.pop();
        }
        if(ans.length()==0 || (k==n)) return "0";//if we can delete whole string then simply answer will be zero
        return ans;
    }
};
