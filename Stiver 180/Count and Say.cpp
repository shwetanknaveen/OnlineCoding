//Problem link - https://leetcode.com/problems/count-and-say/
//If m is the number of characters in the final answer then
//Time complexity = O(mn)
//Space complexity = O(m)
class Solution {
public:
    string countNumber(string s)
    {
        return to_string(s.length())+s[0];//for s=1111 it returns 41 as it is "four ones"
    }
    string countAndSay(int n) {
        string ans = "1";
        for(int k=1;k<n;k++)//for required number of iterations
        {
            string temp = ans;//temporarily store ans at this stage
            ans = "";//as answer will be updated hence empty it here
            int i,j;
            for(i=0;i<temp.length();)//form the group of same numbers
            {
                for(j=i;j<temp.length();)//start from i and keep looking for same numbers
                {
                    if(temp[i]==temp[j])//keep advancing j until same number
                        j++;
                    else break;
                }//j points to number which is not in same group of number which is pointed by i
                ans = ans + countNumber(temp.substr(i,j-i));//add countSay for this group in ans string
                i=j;//look for the next group
            }
        }
        return ans;//return ans after required number of iterations
        
    }
};
