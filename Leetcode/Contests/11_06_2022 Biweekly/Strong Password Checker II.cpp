//Problem link - https://leetcode.com/problems/strong-password-checker-ii/

class Solution {
public:
    bool strongPasswordCheckerII(string p) {
        if(p.length()<8) return false;
        bool lC,uC,oD,oS;
        lC = uC = oD = oS = false;
        for(char c:p)
        {
            if(c>='a' && c<='z') lC = true;
            else if(c>='A' && c<='Z') uC = true;
            else if(c>='0' && c<='9') oD = true;
            else if(c=='!' || c=='@' || c=='#' ||c=='$' ||c=='%' ||c=='^' ||c=='&' ||c=='*' ||c=='(' ||c==')' ||c=='-' ||c=='+') oS = true;
        }
        if(!lC || !uC || !oD || !oS) return false;
        for(int i=1;i<p.length();i++)
        {
            if(p[i]==p[i-1]) return false;
        }
        return true;
    }
};
