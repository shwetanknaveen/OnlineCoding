//Problem link - https://leetcode.com/problems/excel-sheet-column-title/

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        while(columnNumber>26)
        {
            int rem = columnNumber%26;
            if(rem==0)//Let's say column number was 26 so we just want Z and in next step there should be nothing hence we reduce column number by 1 here so that 25/26 becomes zero in next step
            {
                columnNumber--;
                ans += 'Z';    
            }
            else 
                ans += char(rem+'A'-1);
            
            columnNumber /= 26;
        }
        ans += char(columnNumber+'A'-1);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
