//Problem link - https://leetcode.com/problems/string-to-integer-atoi/

//Note - Double data type doesn't have overflow rather it has precisiono error when it goes out of bound

class Solution {
public:
    int myAtoi(string s) {
        int i=0,len = s.length();
        bool neg = false;
       
        for(i=0;i<len;i++)
        {
            if(s[i] == ' ') continue;//skip initial spaces
            if( s[i] != '-' && s[i] != '+' && (s[i]<'0' || s[i]>'9'))//no intial non digit characters except '-' and '+' are allowed
            {
                return 0;
            }
            if(s[i] == '-')
            {
                neg = true;//number is negative
                i++;//actual number will start from next index
                break;
            }
            if(s[i] == '+')
            {
                i++;//actual number will start from the next index
                break;
            }
            if(s[i]>='0' || s[i]<='9')//number starts without - or + sign
                break;
        }
        while(i<len && s[i]=='0')//remove initial 0s
        {
            i++;
        }
        s = s.substr(i,len-i);
        
        len = s.length();
        i = len-1;
        while(i>=0 && (s[i]<'0' || s[i]>'9'))//trailing spaces and characters removal
            i--;
        s = s.substr(0,i+1);
        
        len = s.length();
        for(i=0;i<len;i++)//finding inbetween non digit characters
        {
            if(s[i]<'0' || s[i]>'9')
            {
                i--;//last digit was a valid digit
                break;
            }
        }
        s=s.substr(0,i+1);
        
        len = s.length();
        double ans = 0;
        
        for(i=0;i<len;i++)
        {
            ans = 10*ans + int(s[i]) - int('0');
        }
        if(neg) ans = -ans;//if number started with negative sign
        if(ans>INT_MAX) return INT_MAX;//if number goes out of bound, it has to be clamped to nearest int boundary value
        else if(ans<INT_MIN) return INT_MIN;
        return ans;
    }
};
